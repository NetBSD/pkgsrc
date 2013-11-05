# $NetBSD: Makefile,v 1.39 2013/11/05 18:57:32 adam Exp $

DISTNAME=	imapfilter-2.5.6
CATEGORIES=	mail
MASTER_SITES=	-https://codeload.github.com/lefcha/imapfilter/tar.gz/v${PKGVERSION_NOREV}
FETCH_USING=	curl

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://imapfilter.hellug.gr/
COMMENT=	Mail filtering utility for the IMAP
LICENSE=	mit

LDFLAGS.SunOS+=		-lsocket -lnsl
INSTALLATION_DIRS=	share/examples/imapfilter

post-install:
.for f in config.lua extend.lua
	${INSTALL_DATA} ${WRKSRC}/samples/${f} \
		${DESTDIR}${PREFIX}/share/examples/imapfilter
.endfor

.include "../../devel/pcre/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
