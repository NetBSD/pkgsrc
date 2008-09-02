# $NetBSD: Makefile,v 1.25 2008/09/02 03:11:08 obache Exp $

DISTNAME=		udunits-1.12.1
PKGREVISION=		2
CATEGORIES=		math devel
MASTER_SITES=		ftp://ftp.unidata.ucar.edu/pub/udunits/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.unidata.ucar.edu/software/udunits/
COMMENT=		Library and program for manipulating units of physical quantities

USE_TOOLS+=		perl
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}/src

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
