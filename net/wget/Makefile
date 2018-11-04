# $NetBSD: Makefile,v 1.142 2018/11/04 16:34:57 bsiegert Exp $

DISTNAME=	wget-1.19.5
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		perl pod2man pkg-config

GNU_CONFIGURE=		YES
USE_OLD_DES_API=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

REPLACE_PERL+=		doc/texi2pod.pl

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc
INFO_FILES=		YES

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR}

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
