# $NetBSD: Makefile,v 1.7 2002/12/24 17:21:03 jmmv Exp $

DISTNAME=		udunits
PKGNAME=		udunits-1.11.7
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		http://www.unidata.ucar.edu/packages/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.unidata.ucar.edu/packages/udunits/
COMMENT=		Library and program for manipulating units of physical quantities

UDUNITS_PKGNAME:=	${PKGNAME}
WRKSRC=			${WRKDIR}/${UDUNITS_PKGNAME}/src
DIST_SUBDIR=		${UDUNITS_PKGNAME}

USE_BUILDLINK2=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/UDUNITS/.packlist
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/udunits
CONF_FILES=		${EGDIR}/udunits.dat ${PKG_SYSCONFDIR}/udunits.dat

post-install:
	${RM} -rf ${WRKSRC}/perl/blib/lib

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
