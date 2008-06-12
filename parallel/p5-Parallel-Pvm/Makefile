# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:42 joerg Exp $
#

DISTNAME=	Parallel-Pvm-1.3.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5pvm
CATEGORIES=	parallel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csm.ornl.gov/pvm/pvm_home.html
COMMENT=	Perl module for PVM (Parallel Virtual Machine)

PKG_DESTDIR_SUPPORT=	user-destdir

PVM_ROOT?=		${LOCALBASE}/pvm3
CONFIGURE_ENV+=		PVM_ROOT=${PVM_ROOT:Q} PVM_ARCH=${PVM_ARCH:Q}
MAKE_ENV+=		PVM_ROOT=${PVM_ROOT:Q} PVM_ARCH=${PVM_ARCH:Q}
PERL5_PACKLIST=		auto/Parallel/Pvm/.packlist
MESSAGE_SUBST+=		PVM_ROOT=${PVM_ROOT}
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Parallel-Pvm

INSTALLATION_DIRS=	${EXAMPLES_DIR}

post-build:
.for f in hello.pl hello_other.pl
	${SED} -e 's;@exampledir@;${EXAMPLES_DIR};g' -e 's;@perl@;${PERL5};g' \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-install:
	${INSTALL_SCRIPT} ${WRKDIR}/hello.pl ${DESTDIR}${EXAMPLES_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hello_other.pl ${DESTDIR}${EXAMPLES_DIR}

.include "../../lang/perl5/module.mk"
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
