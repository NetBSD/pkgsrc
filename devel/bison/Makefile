# $NetBSD: Makefile,v 1.31 2002/03/22 19:28:31 tron Exp $

DISTNAME=		bison-1.34
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=bison/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		thorpej@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/bison/bison.html
COMMENT=		GNU yacc(1) replacement

BUILD_USES_MSGFMT=	yes

USE_BUILDLINK_ONLY=	# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-gettext
# We set the timezone to "GMT" below to avoid rebuilds of the info files
# which fail under NetBSD 1.5.
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}" TZ=GMT

CPPFLAGS+=		-Dunix		# for $TMPDIR parsing

INFO_FILES=		bison.info

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
