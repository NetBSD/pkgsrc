# $NetBSD: Makefile,v 1.38 2013/10/30 06:49:54 dholland Exp $

DISTNAME=		imapfilter-${VERSION}
VERSION=		2.5.5
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=  -https://codeload.github.com/lefcha/imapfiler/tar.gz/${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP
LICENSE=		mit

LDFLAGS.SunOS+=		-lsocket -lnsl

FETCH_USING=   curl
WRKSRC= 		${WRKDIR}/lefcha-imapfilter-ef03d60

INSTALLATION_DIRS=	share/examples/imapfilter

post-install:
.for f in config.lua extend.lua
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${DESTDIR}${PREFIX}/share/examples/imapfilter
.endfor

.include "../../lang/lua/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
