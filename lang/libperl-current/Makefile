# $NetBSD: Makefile,v 1.5 2001/02/17 09:07:18 agc Exp $

DISTNAME=		libperl-${PERL_VERSION}
PERL_VERSION=		5.6.0
CATEGORIES=		lang devel perl5
MASTER_SITES=		# empty
DISTFILES=		# empty

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		PERL core library as a shared object

IGNORE=			"${PKGNAME} has been superseded by the libperl package"

USE_PERL5=		# defined
DEPENDS+=		perl>=${PERL_VERSION}:../../lang/perl5-current

EXTRACT_ONLY=		# empty
NO_CHECKSUM=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
.if !exists(/usr/libexec/ld.elf_so) && !exists(/usr/libexec/ld.so)
IGNORE=			${PKGNAME} needs shared objects
.endif
.endif

do-install:		# empty

.include "../../mk/bsd.pkg.mk"
