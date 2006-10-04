# $NetBSD: Makefile,v 1.23 2006/10/04 21:47:58 wiz Exp $

DISTNAME=		udunits
PKGNAME=		udunits-1.12.1
PKGREVISION=		2
CATEGORIES=		math devel
MASTER_SITES=		http://www.unidata.ucar.edu/software/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.unidata.ucar.edu/software/udunits/
COMMENT=		Library and program for manipulating units of physical quantities

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/src
DIST_SUBDIR=		${PKGNAME_NOREV}

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

CPPFLAGS+=		-Df2cFortran -Dunix
PERL5_CONFIGURE=	no
PERL5_PACKLIST=		auto/UDUNITS/.packlist

EGDIR=			${PREFIX}/share/examples/udunits
CONF_FILES=		${EGDIR}/udunits.dat ${PKG_SYSCONFDIR}/udunits.dat

post-install:
	${RM} -rf ${WRKSRC}/perl/blib/lib

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
