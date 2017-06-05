# $NetBSD: Makefile,v 1.27 2017/06/05 14:24:26 ryoon Exp $
#

DISTNAME=	Parallel-Pvm-1.4.0
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	parallel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.csm.ornl.gov/pvm/pvm_home.html
#HOMEPAGE=	http://search.cpan.org/dist/Parallel-Pvm/
COMMENT=	Perl module for PVM (Parallel Virtual Machine)

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
