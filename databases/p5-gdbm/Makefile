# $NetBSD: Makefile,v 1.18 2003/07/17 21:28:43 grant Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
PKGREVISION=		1
SVR4_PKGNAME=		p5gdm
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
CATEGORIES+=		perl5

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File

.include "../../databases/gdbm/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
