# $NetBSD: Makefile,v 1.14 2004/05/23 20:52:09 seb Exp $

DISTNAME=		imapfilter-1.0
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

USE_BUILDLINK3=		yes

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
.for f in sample.config.lua sample.extend.lua
	${INSTALL_DATA} ${WRKSRC}/${f}			\
		${PREFIX}/share/examples/imapfilter
.endfor

.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
