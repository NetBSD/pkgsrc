# $NetBSD: Makefile,v 1.5 2004/04/24 17:32:36 wiz Exp $
#

DISTNAME=	Parallel-Pvm-1.3.0
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5pvm
CATEGORIES=	parallel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.epm.ornl.gov/pvm/pvm_home.html
COMMENT=	Perl module for PVM (Parallel Virtual Machine)

PVM_ROOT?=		${LOCALBASE}/pvm3
CONFIGURE_ENV+=		PVM_ROOT=${PVM_ROOT} PVM_ARCH=${PVM_ARCH}
MAKE_ENV+=		PVM_ROOT=${PVM_ROOT} PVM_ARCH=${PVM_ARCH}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Parallel/Pvm/.packlist
MESSAGE_SUBST+=		PVM_ROOT=${PVM_ROOT}
EXAMPLES_DIR=		${PREFIX}/share/examples/p5-Parallel-Pvm
USE_BUILDLINK3=		YES

post-build:
.for f in hello.pl hello_other.pl
	${SED} -e 's;@exampledir@;${EXAMPLES_DIR};g' -e 's;@perl@;${PERL5};g' \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

post-install:
	${INSTALL_SCRIPT_DIR} ${EXAMPLES_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hello.pl ${EXAMPLES_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/hello_other.pl ${EXAMPLES_DIR}

.include "../../lang/perl5/module.mk"
.include "../../parallel/pvm3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
