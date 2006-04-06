# $NetBSD: Makefile,v 1.90 2006/04/06 03:20:54 jlam Exp $

DISTNAME=	wget-1.10.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

BUILD_USES_MSGFMT=	YES

USE_TOOLS+=		perl

GNU_CONFIGURE=		YES
USE_OLD_DES_API=	YES
USE_PKGLOCALEDIR=	YES

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ENV+=		ac_cv_func_sigsetjmp=yes

EGDIR=			${PREFIX}/share/examples/wget
CONF_FILES=		${EGDIR}/wgetrc ${PKG_SYSCONFDIR}/wgetrc
INFO_FILES=		# PLIST

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
