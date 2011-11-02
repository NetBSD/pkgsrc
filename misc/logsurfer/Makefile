# $NetBSD: Makefile,v 1.20.14.1 2011/11/02 20:10:23 tron Exp $

DISTNAME=	logsurfer-1.8
PKGNAME=	logsurfer-1.8
CATEGORIES=	misc
MASTER_SITES=	http://kerryt.orcon.net.nz/ \
		http://www.crypt.gen.nz/logsurfer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crypt.gen.nz/logsurfer/
COMMENT=	Processes logfiles and performs certain actions

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

EGDIR=		${PREFIX}/share/examples/logsurfer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 ${EGDIR}
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/start-mail/start-mail ${DESTDIR}${EGDIR}/start-mail

.include "../../mk/bsd.pkg.mk"
