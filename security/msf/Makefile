# $NetBSD: Makefile,v 1.13 2007/06/14 12:56:43 gdt Exp $
#

DISTNAME=	framework-2.6
PKGNAME=	msf-2.6
CATEGORIES=	security
MASTER_SITES=	http://www.metasploit.com/tools/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.metasploit.com/
COMMENT=	Platform for developing, testing, and using exploit code

DEPENDS+=	p5-Net-SSLeay>=1.23:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Term-ReadLine>=1.14:../../devel/p5-Term-ReadLine

LICENSE=	inlineegg-license
RESTRICTED=	No permission to redistribute
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

MSFDIR=		${PREFIX}/share/msf
MESSAGE_SUBST+= MSFDIR=${MSFDIR:Q}

USE_TOOLS+=	perl:run
PERL_FILES=	msfcli msfconsole msfelfscan msfencode msflogdump msfpayload \
		msfpescan msfupdate msfweb
REPLACE_PERL+=	${PERL_FILES} tools/socketNinja.pl sdk/formatGen.pl \
		sdk/patternOffset.pl sdk/spitCode.pl src/shellcode/import.pl \
		src/shellcode/win32/standard/build

NO_BUILD=	YES

PKG_OPTIONS_VAR=	PKG_OPTIONS.msf
PKG_SUPPORTED_OPTIONS=	python

.include "../../mk/bsd.options.mk"

# add python support for external payloads
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_PATCH_SCRIPTS=	payloads/external/WindowsSyscall.py \
			payloads/external/bsdx86bind_ie.py \
			payloads/external/bsdx86reverse_ie.py \
			payloads/external/linx86bind_ie.py \
			payloads/external/linx86reverse_ie.py \
			payloads/external/linx86reverse_xor.py \
			payloads/external/win32_stg_winexec.py \
			payloads/external/inlineegg.py
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.endif

INSTALLATION_DIRS=	share/msf/docs share/msf/data share/msf/encoders \
			share/msf/exploits share/msf/extras share/msf/lib \
			share/msf/nops share/msf/payloads/external \
			share/msf/sdk share/msf/src share/msf/tools share/doc

do-install:
	${INSTALL_DATA} ${WRKSRC}/docs/* ${MSFDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/encoders/*.pm ${MSFDIR}/encoders
	${INSTALL_DATA} ${WRKSRC}/exploits/*.pm ${MSFDIR}/exploits
	${INSTALL_DATA} ${WRKSRC}/extras/*.tar.gz ${MSFDIR}/extras

	cd ${PREFIX}/share/doc && ${LN} -s ${MSFDIR}/docs msf
	cd ${WRKSRC}/lib && ${PAX} -rw . ${MSFDIR}/lib
	cd ${WRKSRC}/sdk && ${PAX} -rw . ${MSFDIR}/sdk
	cd ${WRKSRC}/tools && ${PAX} -rw . ${MSFDIR}/tools
	cd ${WRKSRC}/src && ${PAX} -rw . ${MSFDIR}/src
	cd ${WRKSRC}/data && ${PAX} -rw . ${MSFDIR}/data

	${INSTALL_DATA} ${WRKSRC}/nops/*.pm ${MSFDIR}/nops
	${INSTALL_DATA} ${WRKSRC}/payloads/*.pm ${MSFDIR}/payloads
	${INSTALL_DATA} ${WRKSRC}/payloads/external/*.py \
		${MSFDIR}/payloads/external

	set -e; \
	cd ${WRKSRC}; for f in ${PERL_FILES}; do \
		${INSTALL_SCRIPT} "$$f" ${MSFDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
