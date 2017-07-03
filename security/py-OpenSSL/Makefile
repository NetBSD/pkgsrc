# $NetBSD: Makefile,v 1.42 2017/07/03 11:07:59 wiz Exp $

DISTNAME=	pyOpenSSL-17.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	security python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pyOpenSSL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pyca/pyopenssl/
COMMENT=	Python interface to the OpenSSL library
LICENSE=	apache-2.0

DEPENDS+=	${PYPKGPREFIX}-cryptography>=0.3:../../security/py-cryptography
DEPENDS+=	${PYPKGPREFIX}-six>=1.5.2:../../lang/py-six
# TEST_DEPENDS
BUILD_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

# https://github.com/pyca/pyopenssl/issues/596
# https://github.com/pyca/pyopenssl/issues/650
do-test:
	cd ${WRKSRC} && PYTHONPATH=src py.test-${PYVERSSUFFIX} -v -k "not load_privatekey_passphrase_exception and not test_load_privatekey_wrongPassphraseCallback and not test_load_privatekey_passphraseCallback and not test_load_privatekey_passphrase_wrong_return_type and not test_load_privatekey_passphrase_callback_length and not test_dump_privatekey_passphrase_callback and not test_dump_privatekey_passphrase_exception and not test_dump_privatekey_passphraseCallbackLength and not test_set_passwd_cb and not test_passwd_callback_exception and not test_passwd_callback_false and not test_passwd_callback_non_string and not test_passwd_callback_too_long and not test_set_info_callback and not test_load_verify_bytes_cafile and not test_load_verify_unicode_cafile and not test_load_verify_directory_bytes_capath and not test_load_verify_directory_unicode_capath and not test_set_default_verify_paths and not test_set_verify_callback_connection_argument and not test_no_servername and not test_servername and not test_npn_success and not test_npn_client_fail and not test_npn_select_error and not test_npn_advertise_error and not test_alpn_success and not test_alpn_set_on_connection and not test_alpn_server_fail and not test_alpn_callback_exception and not test_get_peer_cert_chain and not test_memory_connect and not test_outgoing_overflow and not test_set_empty_ca_list and not test_set_one_ca_list and not test_set_multiple_ca_list and not test_reset_ca_list and not test_mutated_ca_list and not test_one_add_client and not test_multiple_add_client_ca and not test_set_and_add_client_ca and not test_set_after_add_client_ca and not test_client_negotiates_without_server and not test_client_receives_servers_data and not test_callbacks_are_invoked_with_connections and not test_opaque_data_is_passed_through and not test_server_returns_empty_string and not test_client_returns_false_terminates_handshake and not test_exceptions_in_client_bubble_up and not test_exceptions_in_server_bubble_up and not test_server_must_return_bytes"

.include "../../lang/python/egg.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
