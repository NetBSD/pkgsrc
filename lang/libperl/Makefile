# $NetBSD: Makefile,v 1.27 2002/11/15 00:33:04 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=	libperl-${PERL5_DIST_VERS}
SVR4_PKGNAME=	lperl
CATEGORIES+=	lang devel

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://language.perl.com/index.html
COMMENT=	Perl DynaLoader as a shared object

USE_BUILDLINK2=		# defined
EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

#BUILDLINK_DEPENDS.perl=	perl-${PERL5_DIST_VERS}*

.include "../../mk/bsd.prefs.mk"

MKPIC?=		yes

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
MKPIC=		no
.  endif
.endif

.if ${MKPIC} == "no"
IGNORE=		${PKGNAME} needs shared objects.
.endif

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} -f ${MAKEFILE} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/DynaLoader.o ${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
