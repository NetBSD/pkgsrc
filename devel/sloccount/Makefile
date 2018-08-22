# $NetBSD: Makefile,v 1.4 2018/08/22 09:45:00 wiz Exp $


DISTNAME=	sloccount-2.26
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://www.dwheeler.com/sloccount/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.dwheeler.com/sloccount/
COMMENT=	Counting physical Source Lines of Code (SLOC)

LICENSE=	gnu-gpl-v2

USE_TOOLS+=	flex gunzip perl

MAKE_FILE=	makefile
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	INSTALL_DIR=${DESTDIR}${PREFIX}/libexec/sloccount

.include "../../mk/bsd.prefs.mk"
MAKE_FLAGS+=	DOC_DIR=${DESTDIR}${PREFIX}/share/doc/sloccount
MAKE_FLAGS+=	MAN_DIR=${DESTDIR}${PREFIX}/${PKGMANDIR}
AUTO_MKDIRS=	yes

REPLACE_PERL=		append_license
REPLACE_PERL+=		append_specname
REPLACE_PERL+=		asm_count
REPLACE_PERL+=		break_filelist
REPLACE_PERL+=		cobol_count
REPLACE_PERL+=		count_extensions
REPLACE_PERL+=		extract-count
REPLACE_PERL+=		extract_license
REPLACE_PERL+=		f90_count
REPLACE_PERL+=		fortran_count
REPLACE_PERL+=		generic_count
REPLACE_PERL+=		get_sloc
REPLACE_PERL+=		get_sloc_details
REPLACE_PERL+=		haskell_count
REPLACE_PERL+=		lex_count
REPLACE_PERL+=		modula3_count
REPLACE_PERL+=		objc_count
REPLACE_PERL+=		perl_count
REPLACE_PERL+=		print_sum
REPLACE_PERL+=		python_count
REPLACE_PERL+=		simplecount
REPLACE_PERL+=		sql_count

SUBST_CLASSES+=		generic
SUBST_MESSAGE.generic=	Fixing path to internal generic_count binary.
SUBST_STAGE.generic=	pre-configure
SUBST_SED.generic=	-e 's,^generic_count,${PREFIX}/libexec/sloccount/&,g'
SUBST_FILES.generic=	ada_count awk_count csh_count exp_count lisp_count \
			makefile_count ruby_count sed_count sh_count tcl_count

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Fixing path to internal binaries.
SUBST_STAGE.prefix=	pre-configure
SUBST_SED.prefix=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_FILES.prefix=	compute_all compute_sloc_lang lex_count sloccount

post-install:
	${MV} ${DESTDIR}${PREFIX}/libexec/sloccount/sloccount ${DESTDIR}${PREFIX}/bin/sloccount
	${GUNZIP_CMD} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/sloccount.1.gz

.include "../../mk/bsd.pkg.mk"
