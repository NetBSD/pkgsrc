# $NetBSD: Makefile,v 1.16 2019/08/11 13:21:41 wiz Exp $
#

DISTNAME=		qmqtool-1.15
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
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	src/qmqtool
SUBST_VARS.paths=	PS
SUBST_VARS.paths+=	GREP
SUBST_VARS.paths+=	RCD_SCRIPTS_DIR

SUBST_CLASSES+=		users
SUBST_STAGE.users=	pre-configure
SUBST_FILES.users=	src/qmqtool
SUBST_VARS.users=	QMAIL_SEND_USER
SUBST_VARS.users+=	QMAIL_QUEUE_USER

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin
INSTALLATION_DIRS+=	share/doc/qmqtool share/examples/qmqtool
BUILD_DEFS+=		QMAILDIR QMAIL_QUEUE_USER QMAIL_SEND_USER

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/qmqtool ${DESTDIR}${PREFIX}/sbin
	${INSTALL_MAN} ${WRKSRC}/qmqtool.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8
.for i in Artistic ChangeLog FAQ README
	${INSTALL_DATA} ${WRKSRC}/${i} ${DESTDIR}${PREFIX}/share/doc/qmqtool/${i}
.endfor
	cp -Rp ${WRKSRC}/contrib ${DESTDIR}${PREFIX}/share/examples/qmqtool

.include "../../mk/bsd.pkg.mk"
