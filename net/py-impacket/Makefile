# $NetBSD: Makefile,v 1.3 2020/05/26 22:30:50 adam Exp $

DISTNAME=	impacket-0.9.21
PKGREVISION=	2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/impacket/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.secureauth.com/labs/open-source-tools/impacket
COMMENT=	Collection of Python classes for working with network protocols
LICENSE=	apache-1.1

DEPENDS+=	${PYPKGPREFIX}-OpenSSL>=0.13.1:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-asn1>=0.2.3:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-flask>=1.0:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-ldap3>=2.6:../../databases/py-ldap3
DEPENDS+=	${PYPKGPREFIX}-ldapdomaindump>=0.9.0:../../net/py-ldapdomaindump
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage-[0-9]*:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-future-[0-9]*:../../devel/py-future

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-argparse-[0-9]*:../../devel/py-argparse
.endif

SUBST_CLASSES+=		crypto
SUBST_STAGE.crypto=	pre-configure
SUBST_MESSAGE.crypto=	Switching from py-cryptodomex to py-cryptodome.
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
.for bin in GetADUsers GetNPUsers GetUserSPNs addcomputer atexec dcomexec dpapi \
esentutl findDelegation getArch getPac getST getTGT goldenPac ifmap karmaSMB \
kintercept lookupsid mimikatz mqtt_check mssqlclient mssqlinstance netview \
nmapAnswerMachine ntfs-read ntlmrelayx opdump ping ping6 psexec raiseChild \
rdp_check reg registry-read rpcdump sambaPipe samrdump secretsdump services \
smbclient smbexec smbrelayx smbserver sniff sniffer split ticketConverter \
ticketer wmiexec wmipersist wmiquery
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin}.py ${bin}-${PYVERSSUFFIX}.py || ${TRUE}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
