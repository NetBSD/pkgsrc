# $NetBSD: Makefile,v 1.94 2008/01/18 05:08:51 tnn Exp $

DISTNAME=	wget-1.10.2
PKGREVISION=	2
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

USE_TOOLS+=		perl

GNU_CONFIGURE=		YES
USE_OLD_DES_API=	YES
USE_PKGLOCALEDIR=	YES
USE_TOOLS+=		msgfmt

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		ac_cv_func_sigsetjmp=yes

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc
INFO_FILES=		# PLIST

INSTALL_MAKE_FLAGS=	${MAKE_FLAGS} sysconfdir=${EGDIR:Q}

.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
