# $NetBSD: Makefile,v 1.44 2002/03/30 08:56:36 pooka Exp $

DISTNAME=	wget-1.8.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GNU:=wget/}

MAINTAINER=	michael@pasternak.w.lub.pl
HOMEPAGE=	http://www.gnu.org/software/wget/wget.html
COMMENT=	Retrieve files from the 'net via HTTP and FTP

BUILD_DEPENDS+=	perl>=${PERL5_REQD}:../../lang/perl5

BUILD_USES_MSGFMT=	YES
USE_BUILDLINK_ONLY=	YES

USE_GMAKE=	YES
GNU_CONFIGURE=	YES
MAKE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

INFO_FILES=	wget.info

BUILD_DEFS+=    USE_INET6

# to get USE_INET6
.include "../../mk/bsd.prefs.mk"

# IPv6 support
.if defined(USE_INET6) && ${USE_INET6} == YES
CONFIGURE_ARGS+=        --enable-ipv6
.else
CONFIGURE_ARGS+=        --disable-ipv6
.endif

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
