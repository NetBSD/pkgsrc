# $NetBSD: Makefile,v 1.19 2009/01/18 11:01:56 shattered Exp $

DISTNAME=	logsurfer+-1.7
PKGNAME=	logsurfer-1.7
CATEGORIES=	misc
MASTER_SITES=	http://kerryt.orcon.net.nz/ \
		http://www.crypt.gen.nz/logsurfer/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.crypt.gen.nz/logsurfer/
COMMENT=	Processes logfiles and performs certain actions

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--with-etcdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}

BUILD_DEFS+=	VARBASE

EGDIR=		${PREFIX}/share/examples/logsurfer

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${PKGMANDIR}/man4 ${EGDIR}

post-install:
	mkdir ${EGDIR}
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/start-mail/start-mail ${EGDIR}/start-mail

.include "../../mk/bsd.pkg.mk"
