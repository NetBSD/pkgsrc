# $NetBSD: Makefile,v 1.20 2001/06/07 04:25:33 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=	libperl-${PERL5_VERS}
PERL5_PKG_VERS=	# empty
CATEGORIES+=	lang devel

MAINTAINER=	jlam@netbsd.org
HOMEPAGE=	http://language.perl.com/index.html
COMMENT=	Perl DynaLoader as a shared object

USE_PERL5=	# defined
PERL_REQD=	${PERL5_DIST_VERS}

EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader
WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}

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

.include "../../mk/bsd.pkg.mk"
