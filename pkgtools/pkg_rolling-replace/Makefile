# $NetBSD: Makefile,v 1.5 2007/05/10 02:55:31 tnn Exp $

DISTNAME=	pkg_rolling-replace-0.04
PKGREVISION=	4
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

SUBST_CLASSES+=		makepath
SUBST_STAGE.makepath=	pre-configure
SUBST_MESSAGE.makepath=	Fixing path to ${MAKE}.
SUBST_FILES.makepath=	pkg_rolling-replace.sh
SUBST_SED.makepath=	-e 's,@MAKE@,${MAKE},g'

.include "../../mk/bsd.prefs.mk"

# target exists only to force check-pkgsrc-patch prior to install
do-extract: check-pkgsrc-patch
	cp ${FILESDIR}/pkg_rolling-replace.sh ${WRKSRC}

do-install: check-pkgsrc-patch
	${INSTALL_SCRIPT} ${WRKSRC}/pkg_rolling-replace.sh \
		${PREFIX}/sbin/pkg_rolling-replace
	${INSTALL_SCRIPT} ${FILESDIR}/pkg_rolling-replace.8 \
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
