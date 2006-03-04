# $NetBSD: Makefile,v 1.21 2006/03/04 21:30:00 jlam Exp $

DISTNAME=		imapfilter-1.1.1
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/

MAINTAINER=		pkgsrc-users@NetBSD.org
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
