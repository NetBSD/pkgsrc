# $NetBSD: Makefile,v 1.34 2002/02/18 15:14:10 seb Exp $
# FreeBSD Id: Makefile,v 1.1.1.1 1998/08/09 15:13:33 kuriyama Exp
#

DISTNAME=		gettext-0.10.35
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU:=gettext/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/gettext/gettext.html
COMMENT=		tools for providing messages in different languages

DEPENDS+=		gettext-m4-0.10.35:../../devel/gettext-m4

USE_BUILDLINK_ONLY=	yes
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

INFO_FILES=		gettext.info
TEXINFO_OVERRIDE=	YES

post-patch:
	${RM} -f ${WRKSRC}/intl/libgettext.h
	${RM} -f ${WRKSRC}/intl/libintl.h
	${CP} ${FILESDIR}/libgettext.h ${WRKSRC}/intl

post-configure:
	${RM} -f ${WRKSRC}/intl/libintl.h

post-install:
	cd ${WRKSRC}/intl; ${MAKE_PROGRAM} install-data

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
