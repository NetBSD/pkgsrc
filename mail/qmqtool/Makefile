# $NetBSD: Makefile,v 1.1.1.1 2007/01/18 06:35:24 schmonz Exp $
#

DISTNAME=	qmqtool-current
PKGNAME=	${DISTNAME:S/-current/-1.13/}
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	.tgz

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://jeremy.kister.net/code/qmqtool/
COMMENT=	View and safely modify qmail queue

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=	# none
USE_TOOLS+=	perl:run
NO_BUILD=	yes
REPLACE_PERL=	qmqtool
SPECIAL_PERMS+=	${PREFIX}/sbin/qmqtool ${ROOT_USER} ${ROOT_GROUP} 0700

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/qmqtool
SUBST_SED.paths+=	-e 's,@QMAILDIR@,${QMAILDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PS@,${PS},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP},g'
SUBST_SED.paths+=	-e 's,@RCD_SCRIPTS_DIR@,${RCD_SCRIPTS_DIR},g'
SUBST_STAGE.paths=	do-configure

INSTALLATION_DIRS=	sbin share/doc/qmqtool share/examples/qmqtool

do-install:
	cd ${WRKSRC}; \
	cp qmqtool ${PREFIX}/sbin; \
	cp Artistic ChangeLog FAQ README ${PREFIX}/share/doc/qmqtool; \
	cp -Rp contrib ${PREFIX}/share/examples/qmqtool

.include "../../mk/bsd.pkg.mk"
