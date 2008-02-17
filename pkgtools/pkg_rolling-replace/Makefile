# $NetBSD: Makefile,v 1.17 2008/02/17 10:47:47 apb Exp $

DISTNAME=	pkg_rolling-replace-0.14
CATEGORIES=	pkgtools
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	ngoffee@bbn.com
COMMENT=	Replace/upgrade packages in-place

DEPENDS+=	pkg_chk>=1.76:../../pkgtools/pkg_chk
DEPENDS+=	pkg_tarup>=1.6.6:../../pkgtools/pkg_tarup

PKG_INSTALLATION_TYPES= overwrite pkgviews

USE_TOOLS+=	patch

WRKSRC=		${WRKDIR}
NO_CHECKSUM=	yes
NO_BUILD=	yes
USE_LANGUAGES=	# none

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8

PKG_CHK?=		${PREFIX}/sbin/pkg_chk

SUBST_CLASSES+=		tools
SUBST_STAGE.tools=	pre-configure
SUBST_MESSAGE.tools=	Substituting tool locations.
SUBST_FILES.tools=	pkg_rolling-replace.sh
SUBST_VARS.tools=	PKG_INFO_CMD MAKE PKG_CHK AWK

SUBST_CLASSES+=		makeconf
SUBST_STAGE.makeconf=	pre-configure
SUBST_MESSAGE.makeconf=	Recording default path of mk.conf.
SUBST_FILES.makeconf=	pkg_rolling-replace.sh
SUBST_SED.makeconf=	-e 's,@MAKECONF@,${MAKE:T:Mbmake:S/bmake/${PREFIX}/g}/etc/mk.conf,g'

REPLACE_SH+=		pkg_rolling-replace.sh

.include "../../mk/bsd.prefs.mk"

# target exists only to force check-pkgsrc-patch prior to install
do-extract: check-pkgsrc-patch
	cp ${FILESDIR}/pkg_rolling-replace.sh ${WRKSRC}

do-install: check-pkgsrc-patch
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rolling-replace.sh \
		${PREFIX}/sbin/pkg_rolling-replace
	${INSTALL_MAN} ${FILESDIR}/pkg_rolling-replace.8 \
		${PREFIX}/${PKGMANDIR}/man8/pkg_rolling-replace.8

check-pkgsrc-patch:
	@${ECHO_N} "=> Checking for unsafe_depends support in pkgsrc..."; \
	REPLACE_MK="${PKGSRCDIR}/mk/flavor/pkg/replace.mk"; \
	if [ -f "$$REPLACE_MK" ]; then \
	    if [ "`${EGREP} unsafe_depends=YES $$REPLACE_MK`" ]; then \
	        ${ECHO} "found."; \
		${TRUE}; \
	    else \
	        ${ECHO}; \
	        ${ECHO} "*** pkg_rolling replace requires pkgsrc>=2006Q3" \
	        ${FALSE}; \
            fi; \
	else \
            ${ECHO} "*** pkg_rolling replace requires pkgsrc>=2006Q3"; \
            ${FALSE}; \
        fi

.include "../../mk/bsd.pkg.mk"
