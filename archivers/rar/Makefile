# $NetBSD: Makefile,v 1.39 2005/03/24 21:12:50 wiz Exp $

DISTNAME=		rarbsd
PKGNAME=		rar-2.02
CATEGORIES=		archivers
MASTER_SITES=		ftp://ftp.elf.stuba.sk/pub/pc/pack/
EXTRACT_SUFX=		.sfx

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.rarsoft.com/
COMMENT=		File archiver (binary port)

ONLY_FOR_PLATFORM=	NetBSD-*-i386

RESTRICTED=		Only unmodified original package can be distributed
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

WRKSRC=			${WRKDIR}
EXTRACT_CMD=		${DOWNLOADED_DISTFILE} >/dev/null
NO_BUILDLINK=		yes

pre-extract:
	@if [ -z "$$KERNEL" ]; then \
		KERNEL=`env "PATH=${PATH}:/sbin:/usr/sbin" sysctl -n machdep.booted_kernel` ;\
	fi ;\
	if (${NM} /$$KERNEL | ${GREP} -q compat_12 && \
		${NM} /$$KERNEL | ${GREP} -q exec_nomid && \
		${NM} /$$KERNEL | ${GREP} -q exec_aout); then ${TRUE}; \
	else \
		${ECHO} "****************************************************************";\
		${ECHO} Make can not proceed! In order to extract \(and run\); \
		${ECHO} this package, you must have have booted from a kernel; \
		${ECHO} with options COMPAT_NOMID and COMPAT_12 \(and EXEC_AOUT, if ELF\).; \
		${ECHO} "****************************************************************";\
		${FALSE}; \
	fi
	@${CHMOD} a+x ${DISTDIR}/${DISTFILES}

do-build:
	cd ${WRKSRC} && \
		for i in *.Txt *.Lst; do \
			${TR} -d '\015' < $$i > $$i.tmp; \
			${MV} $$i.tmp $$i; \
		done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/rar ${PREFIX}/share/rar
	cd ${WRKSRC} && \
		${INSTALL_SCRIPT} rar ${PREFIX}/bin/rar && \
		${INSTALL_MAN} Rar.Txt Rar_FAQ.txt TechNote.Txt \
			License.Txt Internet.Txt ${PREFIX}/share/doc/rar && \
		${INSTALL_DATA} RarFiles.Lst \
			${PREFIX}/share/rar/rarfiles.lst && \
		${INSTALL_DATA} default.sfx \
			${PREFIX}/share/rar/default.sfx && \
		${INSTALL_DATA} Dos.SFX \
			${PREFIX}/share/rar/dos.sfx

.include "../../mk/bsd.pkg.mk"
