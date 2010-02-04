# $NetBSD: Makefile,v 1.31 2010/02/04 02:28:33 joerg Exp $

DISTNAME=		imapfilter-2.0.6
PKGREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://imapfilter.hellug.gr/source/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

PKG_DESTDIR_SUPPORT=	user-destdir

LDFLAGS.SunOS+=		-lsocket -lnsl

INSTALLATION_DIRS=	share/examples/imapfilter

post-install:
.for f in sample.config.lua sample.extend.lua
	${INSTALL_DATA} ${WRKSRC}/${f} \
		${DESTDIR}${PREFIX}/share/examples/imapfilter
.endfor

.include "../../lang/lua/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
