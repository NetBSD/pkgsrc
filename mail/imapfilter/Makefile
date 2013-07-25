# $NetBSD: Makefile,v 1.37 2013/07/25 13:25:08 degroote Exp $

DISTNAME=		imapfilter-${VERSION}
VERSION=		2.5.5
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
