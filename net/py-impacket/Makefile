# $NetBSD: Makefile,v 1.9 2022/01/05 15:41:16 wiz Exp $

DISTNAME=	impacket-0.9.24
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/impacket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.secureauth.com/labs/open-source-tools/impacket
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	apache-1.1

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.16.2:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.6.1:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-ldapdomaindump>=0.9.0:../../net/py-ldapdomaindump
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

USE_PKG_RESOURCES=	yes

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
.endif

SUBST_CLASSES+=		crypto
SUBST_STAGE.crypto=	pre-configure
SUBST_MESSAGE.crypto=	Switching from py-cryptodomex to py-cryptodome.
SUBST_FILES.crypto+=	examples/Get-GPPPassword.py
SUBST_FILES.crypto+=	examples/dpapi.py
SUBST_FILES.crypto+=	examples/goldenPac.py
SUBST_FILES.crypto+=	examples/mimikatz.py
SUBST_FILES.crypto+=	examples/rdp_check.py
SUBST_FILES.crypto+=	examples/smbrelayx.py
SUBST_FILES.crypto+=	impacket/crypto.py
SUBST_FILES.crypto+=	impacket/dcerpc/v5/drsuapi.py
SUBST_FILES.crypto+=	impacket/dcerpc/v5/nrpc.py
SUBST_FILES.crypto+=	impacket/dcerpc/v5/rpcrt.py
SUBST_FILES.crypto+=	impacket/dcerpc/v5/samr.py
SUBST_FILES.crypto+=	impacket/dpapi.py
SUBST_FILES.crypto+=	impacket/examples/ntlmrelayx/attacks/ldapattack.py
SUBST_FILES.crypto+=	impacket/examples/ntlmrelayx/clients/dcsyncclient.py
SUBST_FILES.crypto+=	impacket/examples/secretsdump.py
SUBST_FILES.crypto+=	impacket/krb5/crypto.py
SUBST_FILES.crypto+=	impacket/krb5/gssapi.py
SUBST_FILES.crypto+=	impacket/ntlm.py
SUBST_FILES.crypto+=	impacket/smb3.py
SUBST_FILES.crypto+=	tests/SMB_RPC/test_mimilib.py
SUBST_FILES.crypto+=	tests/SMB_RPC/test_nrpc.py
SUBST_FILES.crypto+=	tests/SMB_RPC/test_ntlm.py
SUBST_FILES.crypto+=	tests/SMB_RPC/test_samr.py
SUBST_FILES.crypto+=	tests/misc/test_dpapi.py
SUBST_SED.crypto=	-e 's,Cryptodome,Crypto,'

post-install:
.for bin in Get-GPPPassword GetADUsers GetNPUsers GetUserSPNs PoC PoC2 addcomputer atexec dcomexec dpapi \
esentutl exchanger findDelegation getArch getPac getST getTGT goldenPac karmaSMB keylistattack2 \
kintercept lookupsid mimikatz mqtt_check mssqlclient mssqlinstance netview \
nmapAnswerMachine ntfs-read ntlmrelayx ping ping6 psexec raiseChild \
rbcd rdp_check reg registry-read rpcdump rpcmap sambaPipe samrdump secretsdump services \
smbclient smbexec smbpasswd smbrelayx smbserver sniff sniffer split testTGT testTGT2 ticketConverter \
ticketer wmiexec wmipersist wmiquery
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX}.py || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
