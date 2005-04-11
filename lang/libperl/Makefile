# $NetBSD: Makefile,v 1.35 2005/04/11 21:46:14 tv Exp $

.include "../../lang/perl5/Makefile.common"

PKGNAME=	libperl-${PERL5_DIST_VERS}
SVR4_PKGNAME=	lperl
CATEGORIES+=	lang devel

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://language.perl.com/index.html
COMMENT=	Perl DynaLoader as a shared object

CONFLICTS+=	perl>=5.8

WRKSRC=			${WRKDIR}/${EXTRACT_ELEMENTS}
EXTRACT_ELEMENTS=	${DISTNAME}/ext/DynaLoader

BUILDLINK_DEPENDS.perl=		perl-${PERL5_DIST_VERS}{,nb*}
BUILDLINK_PKGSRCDIR.perl=	../../lang/perl5

.include "../../mk/bsd.prefs.mk"

MKPIC?=		yes

.if ${OPSYS} == "NetBSD"
.  if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
MKPIC=		no
.  endif
.endif

.if ${MKPIC} == "no"
PKG_FAIL_REASON= "${PKGNAME} needs shared objects"
.endif

do-build:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV}				\
		${MAKE_PROGRAM} -f ${MAKEFILE} DynaLoader.o

do-install:
	${INSTALL_DATA} ${WRKSRC}/DynaLoader.o ${PERL5_ARCHLIB}/DynaLoader_pic.o

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
