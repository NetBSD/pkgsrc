# $NetBSD: Makefile,v 1.13 2004/01/20 12:20:05 agc Exp $

DISTNAME=		udunits
PKGNAME=		udunits-1.11.7
PKGREVISION=		1
CATEGORIES=		math devel
MASTER_SITES=		http://www.unidata.ucar.edu/packages/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.unidata.ucar.edu/packages/udunits/
COMMENT=		Library and program for manipulating units of physical quantities

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/src
DIST_SUBDIR=		${PKGNAME_NOREV}

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CPPFLAGS+=		-Df2cFortran -Dunix
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/UDUNITS/.packlist
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

EGDIR=			${PREFIX}/share/examples/udunits
CONF_FILES=		${EGDIR}/udunits.dat ${PKG_SYSCONFDIR}/udunits.dat

post-install:
	${RM} -rf ${WRKSRC}/perl/blib/lib

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
