# $NetBSD: Makefile,v 1.51 2001/12/14 05:32:35 jlam Exp $

.include "../../lang/perl5/Makefile.common"

PKGREVISION=		6
CATEGORIES+=		lang devel

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://language.perl.com/index.html
COMMENT=		Practical Extraction and Report Language

CONFLICTS=		perl-5.00* perl-base-[0-9]* \
			p5-CGI-2.66 p5-CGI-2.75 p5-CGI-2.75.[0-2] \
			p5-Data-Dumper-2.1[0-9][0-9] p5-Data-Dumper-[0-9][0-9] \
			p5-Devel-DProf-[0-9]* p5-Devel-Peek-[0-9]* \
			perl-mk-[0-9]*

HAS_CONFIGURE=		# defined
CONFIGURE_SCRIPT=	./Configure
CONFIGURE_ARGS+=	-sde
CONFIGURE_ARGS+=	-Dprefix="${PREFIX}"
CONFIGURE_ARGS+=	-Dscriptdir="${PREFIX}/bin"
CONFIGURE_ARGS+=	-Darchname="${MACHINE_ARCH}-${LOWER_OPSYS}"
CONFIGURE_ARGS+=	-Doptimize="${CFLAGS}"
CONFIGURE_ARGS+=	-Dcc="${CC}"
CONFIGURE_ARGS+=	-Uusemymalloc
CONFIGURE_ARGS+=	-Uinstallusrbinperl

.include "../../mk/bsd.prefs.mk"

MKPIC?=			yes

# Nail down the needed libraries for each platform here to avoid hidden
# dependencies.  If this isn't defined, then use the perl defaults for the
# particular operating system.
#
LIBSWANTED.NetBSD=	m crypt
LIBSWANTED.SunOS=	m crypt dl socket nsl

# Nail down the directories in which the system libraries may be found.
# If this isn't defined, then use the perl defaults for the particular
# operating system.
#
SYSLIBPATH.NetBSD=	/usr/lib
SYSLIBPATH.SunOS=	/usr/lib

# Nail down the directories in which headers and libraries of
# locally-installed software may be found.
#
LOCLIBPATH=		${LOCALBASE}/lib
LOCINCPATH=		${LOCALBASE}/include

# On a.out platforms, we link with "ld" and on ELF platforms, we link with
# "cc", so we need to use different options to pass the run-time search path
# flags to the link command in the right way.
#
.if ${OBJECT_FMT} == "a.out"
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/-R/g}
.else
LOCLIBRPATHFLAGS=	${LOCLIBPATH:S/^/-Wl,-R/g}
.endif

.if defined(LIBSWANTED.${OPSYS})
CONFIGURE_ARGS+=	-Dlibswanted="${LIBSWANTED.${OPSYS}}"
.endif

.if (${OPSYS} == "NetBSD")
.if !exists(/usr/libexec/ld.so) && !exists(/usr/libexec/ld.elf_so)
MKPIC=			no
.endif
.if (${MACHINE_ARCH} == "sparc64")
# The toolchain on sparc64 is not really production-quality right now, but
# gcc-2.96 is supposed to fix most problems.  Passing -g to the configure
# process triggers -DDEBUGGING, which plays the real trick and circumvents
# code-generation bugs, so we add -g to CFLAGS to at least have a really
# debuggable build.
#
CFLAGS+=		-g -msoft-quad-float -O2
.endif
.elif (${OPSYS} == "SunOS")
CFLAGS=
.endif

.if (${MKPIC} == "yes")
CONFIGURE_ARGS+=	-Duseshrplib
.endif

PERL5_ARCHLIB=		${PREFIX}/lib/perl5/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_SITEARCH=		${PREFIX}/lib/perl5/site_perl/${PERL5_DIST_VERS}/${MACHINE_ARCH}-${LOWER_OPSYS}
PERL5_PACKLIST=		${PERL5_ARCHLIB}/.packlist

# It's tough to guess which hints file will be used, so add our modifications
# to all of them:
#
# - Don't install any manpages in man3; make user use perldoc (to prevent
#   confusion/conflicts with similarly named man2/man3 pages).
#
# - Explicitly set the local compiler search paths to contain only the
#   pkgsrc-controlled directories.
#
post-patch:
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		${CHMOD} +w $${hints};					\
		( ${ECHO} '';						\
		  ${ECHO} 'man3dir=none';				\
		  ${ECHO} 'locincpth="${LOCINCPATH}"';			\
		  ${ECHO} 'loclibpth="${LOCLIBPATH}"';			\
		  ${ECHO} 'ldflags="${LOCLIBRPATHFLAGS} $$ldflags"';	\
		) >> $${hints};						\
	done
.if defined(SYSLIBPATH.${OPSYS})
	hintdir="${WRKSRC}/hints";					\
	for hints in $${hintdir}/*.sh; do				\
		( ${ECHO} "glibpth='${SYSLIBPATH.${OPSYS}}'";		\
		) >> $${hints};						\
	done
.endif

# By default, on platforms that build shared libraries, rebuild the perl
# binary as a statically-linked binary as a speed optimization.  Performance
# increase is only by word-of-mouth -- no actual benchmarks have been
# produced.  However, it has been remarked that the advantage of having a
# statically-linked perl is pretty much non-existent on any platform with
# any reasonable number of registers.  These platforms should be added to
# the list below to bypass the build of the statically-linked perl.
#
.if (${MKPIC} == "yes")
.  for _arch_ in mipsel mipseb
.    if !empty(MACHINE_ARCH:M${_arch_})
STATIC_PERL?=		NO
.    endif
.  endfor
.endif
STATIC_PERL?=		YES

.if defined(STATIC_PERL) && (${STATIC_PERL} == "YES")
STATIC_WRKDIR=		${WRKDIR}/static
STATIC_MAKEFLAGS=	MKPIC=no STATIC_PERL=NO
STATIC_MAKEFLAGS+=	WRKDIR=${STATIC_WRKDIR}
STATIC_MAKEFLAGS+=	ALL_TARGET=perl

post-build:
	cd ${.CURDIR} && ${MAKE} build ${STATIC_MAKEFLAGS}
.endif

post-install:
.if defined(STATIC_PERL) && (${STATIC_PERL} == "YES")
	${RM} ${PREFIX}/bin/perl ${PREFIX}/bin/perl${PERL_DIST_VERS}
	${INSTALL_PROGRAM} ${STATIC_WRKDIR}/${DISTNAME}/perl ${PREFIX}/bin/perl
	${LN} -f ${PREFIX}/bin/perl ${PREFIX}/bin/perl${PERL_DIST_VERS}
.endif
	strip ${PREFIX}/bin/a2p
	strip ${PREFIX}/bin/perl
	${RMDIR} -p ${PERL5_SITEARCH} 2>/dev/null || ${TRUE}
	${RM} -f ${WRKDIR}/bsd.perl.mk
	eval `${PERL5} -V:installsitelib 2>/dev/null` && \
		echo PERL5_SITELIB=$$installsitelib >>${WRKDIR}/bsd.perl.mk     
	eval `${PERL5} -V:installsitearch 2>/dev/null` && \
		echo PERL5_SITEARCH=$$installsitearch >>${WRKDIR}/bsd.perl.mk   
	eval `${PERL5} -V:installarchlib 2>/dev/null` && \
		echo PERL5_ARCHLIB=$$installarchlib >>${WRKDIR}/bsd.perl.mk     
	${INSTALL_DATA} ${WRKDIR}/bsd.perl.mk ${PREFIX}/share/mk/bsd.perl.mk

test:
	-@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} \
		${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} test

.include "../../mk/bsd.pkg.mk"
