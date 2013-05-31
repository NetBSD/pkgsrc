# $NetBSD: Makefile,v 1.7 2013/05/31 12:41:20 wiz Exp $
#

DISTNAME=	qmqtool-current
PKGNAME=	${DISTNAME:S/-current/-1.13/}
PKGREVISION=	2
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

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/qmqtool
SUBST_SED.paths+=	-e 's,@QMAILDIR@,${QMAILDIR:Q},g'
SUBST_SED.paths+=	-e 's,@PS@,${PS},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP},g'
SUBST_SED.paths+=	-e 's,@RCD_SCRIPTS_DIR@,${RCD_SCRIPTS_DIR},g'
SUBST_STAGE.paths=	do-configure

INSTALLATION_DIRS=	sbin share/doc/qmqtool share/examples/qmqtool
BUILD_DEFS+=		QMAILDIR

do-install:
	cd ${WRKSRC}; \
	cp qmqtool ${DESTDIR}${PREFIX}/sbin; \
	cp Artistic ChangeLog FAQ README \
		${DESTDIR}${PREFIX}/share/doc/qmqtool; \
	cp -Rp contrib ${DESTDIR}${PREFIX}/share/examples/qmqtool
	${CHMOD} 0700 ${DESTDIR}${PREFIX}/sbin/qmqtool

.include "../../mk/bsd.pkg.mk"
