# $NetBSD: Makefile,v 1.7 2002/07/17 09:07:43 agc Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	gawk-3.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

ONLY_FOR_PLATFORM=	SunOS-*-*       # in NetBSD base system

# this is a lie we only need ${GETTEXT_PREFIX}/share/gettext/po/Makefile.in.in
BUILD_USES_MSGFMT=	YES

GNU_CONFIGURE=	yes
USE_BUILDLINK_ONLY=	YES
TEXINFO_OVERRIDE=	YES
MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}
EVAL_PREFIX+=		GETTEXT_PREFIX=gettext

.include "../../mk/bsd.prefs.mk"

.if ${GAWK_ENABLE_PORTALS} == "YES"
CONFIGURE_ARGS+=	--enable-portals
.endif

pre-configure:
	${RM} -f ${WRKSRC}/po/Makefile.in.in
	${CP}  ${GETTEXT_PREFIX}/share/gettext/po/Makefile.in.in \
		 ${WRKSRC}/po/Makefile.in.in

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
