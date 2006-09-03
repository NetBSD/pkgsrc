# $NetBSD: Makefile,v 1.1.1.1 2006/09/03 06:27:04 dsainty Exp $

DISTNAME=	sarab-0.2.2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=sarab/}

MAINTAINER=	dsainty@NetBSD.org
HOMEPAGE=	http://sarab.sourceforge.net/
COMMENT=	Schedule And Rotate Automatic Backups
#LICENSE=	GPL

DEPENDS+=	dar-[0-9]*:../../archivers/dar
WRKSRC=		${WRKDIR}/sarab

USE_TOOLS+=		bash:run
PKG_SYSCONFSUBDIR=	sarab

REPLACE_INTERPRETER+=	bash
REPLACE.bash.old=	/bin/bash
REPLACE.bash.new=	${TOOLS_PATH.bash}
REPLACE_FILES.bash=	sarab.sh

EGDIR=		${PREFIX}/share/examples/sarab
CONF_FILES+= ${EGDIR}/rotation.schedule	${PKG_SYSCONFDIR}/rotation.schedule
CONF_FILES+= ${EGDIR}/sarab.conf	${PKG_SYSCONFDIR}/sarab.conf
CONF_FILES+= ${EGDIR}/sarab.dcf	${PKG_SYSCONFDIR}/sarab.dcf

SUBST_CLASSES+=		dar
SUBST_STAGE.dar=	post-patch
SUBST_MESSAGE.dar=	Fix path to DAR utilities
SUBST_FILES.dar=	etc/sarab.conf
SUBST_SED.dar=		-e "s|/usr/local/bin/dar|${PREFIX}/bin/dar|"

# archivers/dar disables building "dar_static"
SUBST_CLASSES+=		nocopy
SUBST_STAGE.nocopy=	post-patch
SUBST_MESSAGE.nocopy=	Do not copy dar_static
SUBST_FILES.nocopy=	etc/sarab.conf
SUBST_SED.nocopy=	-e "s|COPY_DAR=\"yes\"|COPY_DAR=\"no\"|"

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	post-patch
SUBST_MESSAGE.conf=	Fix path to SaraB configuration files
SUBST_FILES.conf=	sarab.sh etc/sarab.conf
SUBST_SED.conf=		-e "s|/etc/sarab|${PKG_SYSCONFDIR}|"

# NetBSD has /kern, and does not have /sys.  Other platforms might
# differ.
SUBST_CLASSES+=		prune
SUBST_STAGE.prune=	post-patch
SUBST_MESSAGE.prune=	Prune /kern instead of /sys
SUBST_FILES.prune=	etc/sarab.dcf
SUBST_SED.prune=	-e "s|--prune sys|--prune kern|"

do-build: # do nothing

do-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	for example in \
			${WRKSRC}/etc/rotation.schedule.README \
			${WRKSRC}/etc/rotation.schedule \
			${WRKSRC}/etc/sarab.conf \
			${WRKSRC}/etc/sarab.dcf \
			${WRKSRC}/etc/examples/*; do \
		${INSTALL_DATA} $${example} ${EGDIR}/; \
	done
	${INSTALL_SCRIPT} ${WRKSRC}/sarab.sh ${PREFIX}/bin/sarab

.include "../../mk/bsd.pkg.mk"
