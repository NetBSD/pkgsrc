# $NetBSD: Makefile,v 1.22 2006/05/31 00:18:28 wiz Exp $

DISTNAME=		imapfilter-1.2.1
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		lefcha@hellug.gr
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

LDFLAGS.SunOS+=		-lsocket -lnsl

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/imapfilter
.for f in sample.config.lua sample.extend.lua
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${PREFIX}/share/examples/imapfilter
.endfor

.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
