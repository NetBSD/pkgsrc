# $NetBSD: Makefile,v 1.21 2004/04/27 05:44:22 snj Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
PKGREVISION=		1
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		perl5

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl interface to gdbm - GNU database manager

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File

.include "../../databases/gdbm/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
