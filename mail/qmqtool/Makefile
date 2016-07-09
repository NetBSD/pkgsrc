# $NetBSD: Makefile,v 1.12 2016/07/09 06:38:31 wiz Exp $
#

DISTNAME=		qmqtool-1.14
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		${HOMEPAGE}/files/
EXTRACT_SUFX=		.tgz

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://jeremy.kister.net/code/qmqtool/
COMMENT=		View and safely modify qmail queue
LICENSE=		artistic

USE_LANGUAGES=		# none
USE_TOOLS+=		perl:run
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}
CONFIGURE_ARGS+=	--perl=${PERL5:Q}
CONFIGURE_ARGS+=	--qmaildir=${QMAILDIR:Q}
CONFIGURE_ARGS+=	--scriptdir=${PREFIX:Q}/sbin
BUILD_TARGET=		qmqtool

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKSRC}/src/qmqtool
SUBST_SED.paths+=	-e 's,@PS@,${PS},g'
SUBST_SED.paths+=	-e 's,@GREP@,${GREP},g'
SUBST_SED.paths+=	-e 's,@RCD_SCRIPTS_DIR@,${RCD_SCRIPTS_DIR},g'
SUBST_STAGE.paths=	pre-configure

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	share/doc/qmqtool share/examples/qmqtool
BUILD_DEFS+=		QMAILDIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmqtool ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/qmqtool.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
.for i in Artistic ChangeLog FAQ README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/qmqtool/${i}
.endfor
	cp -Rp ${WRKSRC}/contrib ${DESTDIR}${PREFIX}/share/examples/qmqtool

.include "../../mk/bsd.pkg.mk"
