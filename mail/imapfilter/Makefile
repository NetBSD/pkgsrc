# $NetBSD: Makefile,v 1.18 2005/09/04 05:00:36 jlam Exp $

DISTNAME=		imapfilter-1.0.1
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		seb@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP


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
