# $NetBSD: Makefile,v 1.37 2012/10/02 21:25:36 asau Exp $

.include "../../lang/perl5/Makefile.common"
PKGNAME=	p5-${DISTNAME:S/perl/gdbm/}
PKGREVISION=	2
SVR4_PKGNAME=	p5gdm
CATEGORIES=	databases perl5

#PATCHDIR=	${.CURDIR}/../../lang/perl5/patches
DISTINFO_FILE=	${.CURDIR}/../../lang/perl5/distinfo

COMMENT=	Perl interface to gdbm - GNU database manager
LICENSE=	${PERL5_LICENSE}

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

PERL5_PACKLIST=		auto/GDBM_File/.packlist

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
