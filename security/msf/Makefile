# $NetBSD: Makefile,v 1.1.1.1 2004/10/19 16:38:22 adrianp Exp $
#

DISTNAME=	framework-2.2
PKGNAME=	msf-2.2
CATEGORIES=	security
MASTER_SITES=	http://www.metasploit.com/tools/

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://www.metasploit.com/
COMMENT=	Platform for developing, testing, and using exploit code

DEPENDS+=	p5-Net-SSLeay>=1.23:../../security/p5-Net-SSLeay
DEPENDS+=	p5-Term-ReadLine>=1.14:../../devel/p5-Term-ReadLine

MSFDIR?=	${PREFIX}/share/msf
MSFDOC?=	${PREFIX}/share/doc/msf
MESSAGE_SUBST+= MSFDIR=${MSFDIR}

PERL5_REQD=	5.6.0
USE_PERL5=	YES
PERL_FILES=	msfcli msfconsole msfdldebug msfencode msflogdump msfpayload \
		msfpayload.cgi msfpescan msfweb msfupdate
REPLACE_PERL+=	${PERL_FILES} tools/socketNinja.pl sdk/formatGen.pl \
		sdk/patternOffset.pl sdk/spitCode.pl

NO_BUILDLINK=	YES
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
			payloads/external/win32_stg_winexec.py
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.endif

do-install:
	${INSTALL_DATA_DIR} ${MSFDIR}
	${INSTALL_DATA_DIR} ${MSFDIR}/docs
	${INSTALL_DATA_DIR} ${MSFDIR}/data
	${INSTALL_DATA_DIR} ${MSFDIR}/encoders
	${INSTALL_DATA_DIR} ${MSFDIR}/exploits
	${INSTALL_DATA_DIR} ${MSFDIR}/extras
	${INSTALL_DATA_DIR} ${MSFDIR}/lib
	${INSTALL_DATA_DIR} ${MSFDIR}/nops
	${INSTALL_DATA_DIR} ${MSFDIR}/payloads
	${INSTALL_DATA_DIR} ${MSFDIR}/payloads/external
	${INSTALL_DATA_DIR} ${MSFDIR}/sdk
	${INSTALL_DATA_DIR} ${MSFDIR}/tools
	${INSTALL_DATA_DIR} ${MSFDIR}/src

	${INSTALL_DATA} ${WRKSRC}/docs/* ${MSFDIR}/docs
	${INSTALL_DATA} ${WRKSRC}/data/* ${MSFDIR}/data
	${INSTALL_DATA} ${WRKSRC}/encoders/*.pm ${MSFDIR}/encoders
	${INSTALL_DATA} ${WRKSRC}/exploits/*.pm ${MSFDIR}/exploits
	${INSTALL_DATA} ${WRKSRC}/extras/*.tar.gz ${MSFDIR}/extras

	cd ${PREFIX}/share/doc && ${LN} -s ${MSFDIR}/docs msf
	cd ${WRKSRC}/lib && ${PAX} -rw . ${MSFDIR}/lib
	cd ${WRKSRC}/sdk && ${PAX} -rw . ${MSFDIR}/sdk
	cd ${WRKSRC}/tools && ${PAX} -rw . ${MSFDIR}/tools
	cd ${WRKSRC}/src && ${PAX} -rw . ${MSFDIR}/src

	${INSTALL_DATA} ${WRKSRC}/nops/*.pm ${MSFDIR}/nops
	${INSTALL_DATA} ${WRKSRC}/payloads/*.pm ${MSFDIR}/payloads
	${INSTALL_DATA} ${WRKSRC}/payloads/external/*.py \
		${MSFDIR}/payloads/external

	cd ${WRKSRC}; for f in ${PERL_FILES}; do \
		${INSTALL_SCRIPT} $$f ${MSFDIR}; \
	done

.include "../../mk/bsd.pkg.mk"
