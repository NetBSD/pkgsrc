# $NetBSD: Makefile,v 1.44 2006/05/17 06:12:27 rillig Exp $

DISTNAME=		rarbsd
PKGNAME=		rar-2.02
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.elf.stuba.sk/pub/pc/pack/
EXTRACT_SUFX=		.sfx

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/
COMMENT=		File archiver (binary port)

ONLY_FOR_PLATFORM=	NetBSD-*-i386

LICENSE=		rar-license
RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${DOWNLOADED_DISTFILE} >/dev/null

pre-extract:
	${_PKG_SILENT}${_PKG_DEBUG} set -e; set -u;			\
	if [ -z "$${KERNEL-}" ]; then					\
		KERNEL=/`env PATH="$${PATH}:/sbin:/usr/sbin" sysctl -n machdep.booted_kernel`; \
	fi;								\
	if [ ! -f "$$KERNEL" ]; then					\
		${ECHO} "No kernel image found. Let's try without.";	\
	elif (${NM} "$$KERNEL" | ${GREP} -q compat_12 &&		\
		${NM} "$$KERNEL" | ${GREP} -q exec_nomid &&		\
		${NM} "$$KERNEL" | ${GREP} -q exec_aout); then		\
		${TRUE};						\
	else								\
		${ECHO} "Make can not proceed! In order to extract (and run)";	\
		${ECHO} "this package, you must have have booted from a kernel"; \
		${ECHO} "with options COMPAT_NOMID and COMPAT_12 (and EXEC_AOUT, if ELF)."; \
		${FALSE};						\
	fi
	${CHMOD} a+x ${DISTDIR:Q}/${DISTFILES:Q}

do-build:
	${_PKG_SILENT}${_PKG_DEBUG} set -e; set -u;			\
	cd ${WRKSRC:Q};							\
	for i in *.Txt *.Lst; do					\
		${TR} -d '\015' < "$$i" > "$$i".tmp;			\
		${MV} "$$i".tmp "$$i";					\
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX:Q}/share/doc/rar ${PREFIX:Q}/share/rar
	cd ${WRKSRC:Q} && \
		${INSTALL_SCRIPT} rar ${PREFIX:Q}/bin/rar && \
		${INSTALL_MAN} Rar.Txt Rar_FAQ.txt TechNote.Txt \
			License.Txt Internet.Txt ${PREFIX:Q}/share/doc/rar && \
		${INSTALL_DATA} RarFiles.Lst \
			${PREFIX:Q}/share/rar/rarfiles.lst && \
		${INSTALL_DATA} default.sfx \
			${PREFIX:Q}/share/rar/default.sfx && \
		${INSTALL_DATA} Dos.SFX \
			${PREFIX:Q}/share/rar/dos.sfx

.include "../../mk/bsd.pkg.mk"
