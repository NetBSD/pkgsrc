# $NetBSD: Makefile,v 1.14 2002/10/10 00:39:24 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=		p5-gdbm-1.05
SVR4_PKGNAME=		p5gdm
CATEGORIES+=		perl5

MAINTAINER=		packages@netbsd.org
COMMENT=		perl interface to gdbm - GNU database manager

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/GDBM_File/.packlist

EXTRACT_ELEMENTS=	${DISTNAME}/ext/GDBM_File
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

.include "../../databases/gdbm/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
