# $NetBSD: Makefile,v 1.1.1.1 1998/12/05 16:14:53 tv Exp $
#

DISTNAME=	eperl-2.2.14
CATEGORIES=	lang perl5 textproc
MASTER_SITES=	http://www.engelschall.com/sw/eperl/distrib/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/sw/eperl/

DEPENDS=	libperl-5.00404:../../lang/libperl

GNU_CONFIGURE=	yes
ALL_TARGET=	all libeperl.a

post-build:
	@cd ${WRKSRC}/mod/Parse && ${PREFIX}/bin/perl Makefile.PL && ${MAKE}

post-install:
	@cd ${WRKSRC}/mod/Parse && ${MAKE} install

.include "../../mk/bsd.pkg.mk"
