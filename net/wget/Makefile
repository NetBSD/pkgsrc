# $NetBSD: Makefile,v 1.56 2002/12/17 15:57:31 tron Exp $

DISTNAME=	wget-1.8.2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

USE_PERL5=	build

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK2=		YES

USE_GMAKE=		YES
GNU_CONFIGURE=		YES
USE_PKGLOCALEDIR=	YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc

INFO_FILES=		wget.info

WGET_USE_SSL?=		YES

.if ${WGET_USE_SSL} == YES
.include "../../security/openssl/buildlink2.mk"
CONFIGURE_ARGS+=--with-ssl=${SSLBASE}
.endif

CONFIGURE_ARGS+=--with-ssl=${SSLBASE}

.include "../../devel/gettext-lib/buildlink2.mk"

.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
