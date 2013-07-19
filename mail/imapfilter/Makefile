# $NetBSD: Makefile,v 1.36 2013/07/19 13:58:56 degroote Exp $

DISTNAME= 		v${VERSION}
PKGNAME=		imapfilter-${VERSION}
VERSION=		2.5.5
CATEGORIES=		mail
MASTER_SITES=	http://github.com/lefcha/imapfilter/archive/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://imapfilter.hellug.gr/
COMMENT=		Mail filtering utility for the IMAP

LDFLAGS.SunOS+=		-lsocket -lnsl

WRKSRC=     ${WRKDIR}/imapfilter-${VERSION}

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
