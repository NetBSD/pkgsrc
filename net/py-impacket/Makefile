# $NetBSD: Makefile,v 1.12 2024/02/29 20:56:48 adam Exp $

DISTNAME=	impacket-0.11.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/impacket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.secureauth.com/labs/open-source-tools/impacket
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	apache-1.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-charset-normalizer-[0-9]*:../../converters/py-charset-normalizer
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-dsinternals-[0-9]*:../../databases/py-dsinternals
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.6.1:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-ldapdomaindump>=0.9.0:../../net/py-ldapdomaindump
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage

PYTHON_VERSIONS_INCOMPATIBLE=	27

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
SUBST_FILES.crypto+=	tests/SMB_RPC/test_ntlm.py
SUBST_FILES.crypto+=	tests/dcerpc/test_mimilib.py
SUBST_FILES.crypto+=	tests/dcerpc/test_nrpc.py
SUBST_FILES.crypto+=	tests/dcerpc/test_samr.py
SUBST_FILES.crypto+=	tests/misc/test_dpapi.py
SUBST_SED.crypto=	-e 's,Cryptodome,Crypto,'

post-install:
.for bin in DumpNTLMInfo Get-GPPPassword GetADUsers GetNPUsers GetUserSPNs addcomputer atexec \
	changepasswd dcomexec dpapi esentutl exchanger findDelegation getArch getPac getST getTGT \
	goldenPac karmaSMB keylistattack kintercept lookupsid machine_role mimikatz mqtt_check \
	mssqlclient mssqlinstance net netview nmapAnswerMachine ntfs-read ntlmrelayx ping ping6 \
	psexec raiseChild rbcd rdp_check reg registry-read rpcdump rpcmap sambaPipe samrdump \
	secretsdump services smbclient smbexec smbpasswd smbrelayx smbserver sniff sniffer \
	split ticketConverter ticketer tstool wmiexec wmipersist wmiquery
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX}.py || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
