# $NetBSD: Makefile,v 1.9 2002/11/30 14:55:06 grant Exp $
# FreeBSD Id: Makefile,v 1.13 1999/01/27 07:41:14 fenner Exp $

DISTNAME=	gawk-3.1.0
CATEGORIES=	lang
MASTER_SITES=	${MASTER_SITE_GNU:=gawk/}

MAINTAINER=	bouyer@netbsd.org
HOMEPAGE=	http://www.gnu.org/software/gawk/gawk.html
COMMENT=	GNU awk

ONLY_FOR_PLATFORM=	SunOS-*-*       # in NetBSD base system

# We need ${GETTEXT_PREFIX}/share/gettext/po/Makefile.in.in.
BUILD_DEPENDS+=		gettext>=0.10.35nb1:../../devel/gettext

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
TEXINFO_OVERRIDE=	# defined
EVAL_PREFIX+=		GETTEXT_PREFIX=gettext

.include "../../mk/bsd.prefs.mk"

.if ${GAWK_ENABLE_PORTALS} == "YES"
CONFIGURE_ARGS+=	--enable-portals
.endif

pre-configure:
	${RM} -f ${WRKSRC}/po/Makefile.in.in
	${CP} ${GETTEXT_PREFIX}/share/gettext/po/Makefile.in.in \
		 ${WRKSRC}/po/Makefile.in.in

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
