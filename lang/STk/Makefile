# $NetBSD: Makefile,v 1.22 2012/10/02 20:11:35 asau Exp $

DISTNAME=	STk-4.0.1
PKGREVISION=		3
CATEGORIES=		lang
MASTER_SITES=		ftp://kaolin.unice.fr/pub/STk/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://kaolin.unice.fr/STk/
COMMENT=	Scheme interpreter with full access to the Tk graphical package

CONFLICTS+=	snow-[0-9]*

MAKE_JOBS_SAFE=		no

OSVERSION_SPECIFIC=	yes
GNU_CONFIGURE=		yes

BUILDLINK_DEPMETHOD.libXt=	build

MAKE_ENV+=		X11_LDFLAGS=${X11_LDFLAGS:M*:Q}

# Respin these symlinks so they aren't absolute.
STKVER=${DISTNAME:S/STk-//}
STKDIR=lib/stk/${STKVER}/${OPSYS}-${OS_VERSION}-${MACHINE_ARCH}
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/snow-${STKVER}
	${RM} -f ${DESTDIR}${PREFIX}/bin/stk-${STKVER}
	${LN} -s ../${STKDIR}/snow ${DESTDIR}${PREFIX}/bin/snow-${STKVER}
	${LN} -s ../${STKDIR}/stk ${DESTDIR}${PREFIX}/bin/stk-${STKVER}

.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
