# $NetBSD: Makefile,v 1.26 2002/07/22 22:03:34 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=	libperl-${PERL5_DIST_VERS}
SVR4_PKGNAME=	lperl
CATEGORIES+=	lang devel

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://language.perl.com/index.html
COMMENT=	Perl DynaLoader as a shared object

USE_BUILDLINK_ONLY=	YES
EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

BUILDLINK_DEPENDS.perl=	perl-${PERL5_DIST_VERS}*

.include "../../mk/bsd.prefs.mk"

MKPIC?=		yes

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
MKPIC=		no
.endif
.endif

.if ${MKPIC} == "no"
IGNORE=		${PKGNAME} needs shared objects
.endif

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} -f ${MAKEFILE} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/DynaLoader.o ${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
