$NetBSD: patch-erlang.mk,v 1.1 2024/08/21 15:00:33 adam Exp $

Regenerated erlang.mk from Erlang 27 support, from https://github.com/ninenines/erlang.mk
Stripped -Werror.

--- erlang.mk.orig	2024-04-17 17:02:51.000000000 +0000
+++ erlang.mk
@@ -17,7 +17,7 @@
 ERLANG_MK_FILENAME := $(realpath $(lastword $(MAKEFILE_LIST)))
 export ERLANG_MK_FILENAME
 
-ERLANG_MK_VERSION = 94718f7-dirty
+ERLANG_MK_VERSION = b8a27ab-dirty
 ERLANG_MK_WITHOUT = 
 
 # Make 3.81 and 3.82 are deprecated.
@@ -171,7 +171,7 @@ endef
 
 # Adding erlang.mk to make Erlang scripts who call init:get_plain_arguments() happy.
 define erlang
-$(ERL) $2 -pz $(ERLANG_MK_TMP)/rebar/ebin -eval "$(subst $(newline),,$(call escape_dquotes,$1))" -- erlang.mk
+$(ERL) $2 -pz $(ERLANG_MK_TMP)/rebar3/_build/prod/lib/*/ebin/ -eval "$(subst $(newline),,$(call escape_dquotes,$1))" -- erlang.mk
 endef
 
 ifeq ($(PLATFORM),msys2)
@@ -185,7 +185,8 @@ core_http_get = curl -Lf$(if $(filter-ou
 core_eq = $(and $(findstring $(1),$(2)),$(findstring $(2),$(1)))
 
 # We skip files that contain spaces because they end up causing issues.
-core_find = $(if $(wildcard $1),$(shell find $(1:%/=%) \( -type l -o -type f \) -name $(subst *,\*,$2) | grep -v " "))
+# Files that begin with a dot are already ignored by the wildcard function.
+core_find = $(foreach f,$(wildcard $(1:%/=%)/*),$(if $(wildcard $f/.),$(call core_find,$f,$2),$(if $(filter $(subst *,%,$2),$f),$(if $(wildcard $f),$f))))
 
 core_lc = $(subst A,a,$(subst B,b,$(subst C,c,$(subst D,d,$(subst E,e,$(subst F,f,$(subst G,g,$(subst H,h,$(subst I,i,$(subst J,j,$(subst K,k,$(subst L,l,$(subst M,m,$(subst N,n,$(subst O,o,$(subst P,p,$(subst Q,q,$(subst R,r,$(subst S,s,$(subst T,t,$(subst U,u,$(subst V,v,$(subst W,w,$(subst X,x,$(subst Y,y,$(subst Z,z,$(1)))))))))))))))))))))))))))
 
@@ -252,15 +253,6 @@ $(KERL_INSTALL_DIR)/$(1): $(KERL)
 	fi
 endef
 
-define kerl_hipe_target
-$(KERL_INSTALL_DIR)/$1-native: $(KERL)
-	$(verbose) if [ ! -d $$@ ]; then \
-		KERL_CONFIGURE_OPTIONS=--enable-native-libs \
-			MAKEFLAGS="$(KERL_MAKEFLAGS)" $(KERL) build git $(OTP_GIT) $1 $1-native; \
-		$(KERL) install $1-native $(KERL_INSTALL_DIR)/$1-native; \
-	fi
-endef
-
 $(KERL): $(KERL_DIR)
 
 $(KERL_DIR): | $(ERLANG_MK_TMP)
@@ -283,10 +275,10 @@ ERLANG_OTP := $(notdir $(lastword $(sort
 endif
 
 ERLANG_OTP ?=
-ERLANG_HIPE ?=
 
 # Use kerl to enforce a specific Erlang/OTP version for a project.
 ifneq ($(strip $(ERLANG_OTP)),)
+
 export PATH := $(KERL_INSTALL_DIR)/$(ERLANG_OTP)/bin:$(PATH)
 SHELL := env PATH=$(PATH) $(SHELL)
 $(eval $(call kerl_otp_target,$(ERLANG_OTP)))
@@ -297,20 +289,6 @@ $(info Building Erlang/OTP $(ERLANG_OTP)
 $(shell $(MAKE) $(KERL_INSTALL_DIR)/$(ERLANG_OTP) ERLANG_OTP=$(ERLANG_OTP) BUILD_ERLANG_OTP=1 >&2)
 endif
 
-else
-# Same for a HiPE enabled VM.
-ifneq ($(strip $(ERLANG_HIPE)),)
-export PATH := $(KERL_INSTALL_DIR)/$(ERLANG_HIPE)-native/bin:$(PATH)
-SHELL := env PATH=$(PATH) $(SHELL)
-$(eval $(call kerl_hipe_target,$(ERLANG_HIPE)))
-
-# Build Erlang/OTP only if it doesn't already exist.
-ifeq ($(wildcard $(KERL_INSTALL_DIR)/$(ERLANG_HIPE)-native)$(BUILD_ERLANG_OTP),)
-$(info Building HiPE-enabled Erlang/OTP $(ERLANG_OTP)... Please wait...)
-$(shell $(MAKE) $(KERL_INSTALL_DIR)/$(ERLANG_HIPE)-native ERLANG_HIPE=$(ERLANG_HIPE) BUILD_ERLANG_OTP=1 >&2)
-endif
-
-endif
 endif
 
 PACKAGES += aberth
@@ -329,22 +307,6 @@ pkg_active_fetch = git
 pkg_active_repo = https://github.com/proger/active
 pkg_active_commit = master
 
-PACKAGES += actordb_core
-pkg_actordb_core_name = actordb_core
-pkg_actordb_core_description = ActorDB main source
-pkg_actordb_core_homepage = http://www.actordb.com/
-pkg_actordb_core_fetch = git
-pkg_actordb_core_repo = https://github.com/biokoda/actordb_core
-pkg_actordb_core_commit = master
-
-PACKAGES += actordb_thrift
-pkg_actordb_thrift_name = actordb_thrift
-pkg_actordb_thrift_description = Thrift API for ActorDB
-pkg_actordb_thrift_homepage = http://www.actordb.com/
-pkg_actordb_thrift_fetch = git
-pkg_actordb_thrift_repo = https://github.com/biokoda/actordb_thrift
-pkg_actordb_thrift_commit = master
-
 PACKAGES += aleppo
 pkg_aleppo_name = aleppo
 pkg_aleppo_description = Alternative Erlang Pre-Processor
@@ -361,14 +323,6 @@ pkg_alog_fetch = git
 pkg_alog_repo = https://github.com/siberian-fast-food/alogger
 pkg_alog_commit = master
 
-PACKAGES += amqp_client
-pkg_amqp_client_name = amqp_client
-pkg_amqp_client_description = RabbitMQ Erlang AMQP client
-pkg_amqp_client_homepage = https://www.rabbitmq.com/erlang-client-user-guide.html
-pkg_amqp_client_fetch = git
-pkg_amqp_client_repo = https://github.com/rabbitmq/rabbitmq-erlang-client.git
-pkg_amqp_client_commit = master
-
 PACKAGES += annotations
 pkg_annotations_name = annotations
 pkg_annotations_description = Simple code instrumentation utilities
@@ -377,14 +331,6 @@ pkg_annotations_fetch = git
 pkg_annotations_repo = https://github.com/hyperthunk/annotations
 pkg_annotations_commit = master
 
-PACKAGES += antidote
-pkg_antidote_name = antidote
-pkg_antidote_description = Large-scale computation without synchronisation
-pkg_antidote_homepage = https://syncfree.lip6.fr/
-pkg_antidote_fetch = git
-pkg_antidote_repo = https://github.com/SyncFree/antidote
-pkg_antidote_commit = master
-
 PACKAGES += apns
 pkg_apns_name = apns
 pkg_apns_description = Apple Push Notification Server for Erlang
@@ -401,14 +347,6 @@ pkg_asciideck_fetch = git
 pkg_asciideck_repo = https://github.com/ninenines/asciideck
 pkg_asciideck_commit = master
 
-PACKAGES += azdht
-pkg_azdht_name = azdht
-pkg_azdht_description = Azureus Distributed Hash Table (DHT) in Erlang
-pkg_azdht_homepage = https://github.com/arcusfelis/azdht
-pkg_azdht_fetch = git
-pkg_azdht_repo = https://github.com/arcusfelis/azdht
-pkg_azdht_commit = master
-
 PACKAGES += backoff
 pkg_backoff_name = backoff
 pkg_backoff_description = Simple exponential backoffs in Erlang
@@ -449,14 +387,6 @@ pkg_beam_fetch = git
 pkg_beam_repo = https://github.com/tonyrog/beam
 pkg_beam_commit = master
 
-PACKAGES += beanstalk
-pkg_beanstalk_name = beanstalk
-pkg_beanstalk_description = An Erlang client for beanstalkd
-pkg_beanstalk_homepage = https://github.com/tim/erlang-beanstalk
-pkg_beanstalk_fetch = git
-pkg_beanstalk_repo = https://github.com/tim/erlang-beanstalk
-pkg_beanstalk_commit = master
-
 PACKAGES += bear
 pkg_bear_name = bear
 pkg_bear_description = a set of statistics functions for erlang
@@ -505,14 +435,6 @@ pkg_bitcask_fetch = git
 pkg_bitcask_repo = https://github.com/basho/bitcask
 pkg_bitcask_commit = develop
 
-PACKAGES += bitstore
-pkg_bitstore_name = bitstore
-pkg_bitstore_description = A document based ontology development environment
-pkg_bitstore_homepage = https://github.com/bdionne/bitstore
-pkg_bitstore_fetch = git
-pkg_bitstore_repo = https://github.com/bdionne/bitstore
-pkg_bitstore_commit = master
-
 PACKAGES += bootstrap
 pkg_bootstrap_name = bootstrap
 pkg_bootstrap_description = A simple, yet powerful Erlang cluster bootstrapping application.
@@ -577,14 +499,6 @@ pkg_cake_fetch = git
 pkg_cake_repo = https://github.com/darach/cake-erl
 pkg_cake_commit = master
 
-PACKAGES += carotene
-pkg_carotene_name = carotene
-pkg_carotene_description = Real-time server
-pkg_carotene_homepage = https://github.com/carotene/carotene
-pkg_carotene_fetch = git
-pkg_carotene_repo = https://github.com/carotene/carotene
-pkg_carotene_commit = master
-
 PACKAGES += cberl
 pkg_cberl_name = cberl
 pkg_cberl_description = NIF based Erlang bindings for Couchbase
@@ -627,7 +541,7 @@ pkg_check_node_commit = master
 
 PACKAGES += chronos
 pkg_chronos_name = chronos
-pkg_chronos_description = Timer module for Erlang that makes it easy to abstact time out of the tests.
+pkg_chronos_description = Timer module for Erlang that makes it easy to abstract time out of the tests.
 pkg_chronos_homepage = https://github.com/lehoff/chronos
 pkg_chronos_fetch = git
 pkg_chronos_repo = https://github.com/lehoff/chronos
@@ -673,54 +587,6 @@ pkg_cloudi_service_api_requests_fetch =
 pkg_cloudi_service_api_requests_repo = https://github.com/CloudI/cloudi_service_api_requests
 pkg_cloudi_service_api_requests_commit = master
 
-PACKAGES += cloudi_service_db
-pkg_cloudi_service_db_name = cloudi_service_db
-pkg_cloudi_service_db_description = CloudI Database (in-memory/testing/generic)
-pkg_cloudi_service_db_homepage = http://cloudi.org/
-pkg_cloudi_service_db_fetch = git
-pkg_cloudi_service_db_repo = https://github.com/CloudI/cloudi_service_db
-pkg_cloudi_service_db_commit = master
-
-PACKAGES += cloudi_service_db_cassandra
-pkg_cloudi_service_db_cassandra_name = cloudi_service_db_cassandra
-pkg_cloudi_service_db_cassandra_description = Cassandra CloudI Service
-pkg_cloudi_service_db_cassandra_homepage = http://cloudi.org/
-pkg_cloudi_service_db_cassandra_fetch = git
-pkg_cloudi_service_db_cassandra_repo = https://github.com/CloudI/cloudi_service_db_cassandra
-pkg_cloudi_service_db_cassandra_commit = master
-
-PACKAGES += cloudi_service_db_cassandra_cql
-pkg_cloudi_service_db_cassandra_cql_name = cloudi_service_db_cassandra_cql
-pkg_cloudi_service_db_cassandra_cql_description = Cassandra CQL CloudI Service
-pkg_cloudi_service_db_cassandra_cql_homepage = http://cloudi.org/
-pkg_cloudi_service_db_cassandra_cql_fetch = git
-pkg_cloudi_service_db_cassandra_cql_repo = https://github.com/CloudI/cloudi_service_db_cassandra_cql
-pkg_cloudi_service_db_cassandra_cql_commit = master
-
-PACKAGES += cloudi_service_db_couchdb
-pkg_cloudi_service_db_couchdb_name = cloudi_service_db_couchdb
-pkg_cloudi_service_db_couchdb_description = CouchDB CloudI Service
-pkg_cloudi_service_db_couchdb_homepage = http://cloudi.org/
-pkg_cloudi_service_db_couchdb_fetch = git
-pkg_cloudi_service_db_couchdb_repo = https://github.com/CloudI/cloudi_service_db_couchdb
-pkg_cloudi_service_db_couchdb_commit = master
-
-PACKAGES += cloudi_service_db_elasticsearch
-pkg_cloudi_service_db_elasticsearch_name = cloudi_service_db_elasticsearch
-pkg_cloudi_service_db_elasticsearch_description = elasticsearch CloudI Service
-pkg_cloudi_service_db_elasticsearch_homepage = http://cloudi.org/
-pkg_cloudi_service_db_elasticsearch_fetch = git
-pkg_cloudi_service_db_elasticsearch_repo = https://github.com/CloudI/cloudi_service_db_elasticsearch
-pkg_cloudi_service_db_elasticsearch_commit = master
-
-PACKAGES += cloudi_service_db_memcached
-pkg_cloudi_service_db_memcached_name = cloudi_service_db_memcached
-pkg_cloudi_service_db_memcached_description = memcached CloudI Service
-pkg_cloudi_service_db_memcached_homepage = http://cloudi.org/
-pkg_cloudi_service_db_memcached_fetch = git
-pkg_cloudi_service_db_memcached_repo = https://github.com/CloudI/cloudi_service_db_memcached
-pkg_cloudi_service_db_memcached_commit = master
-
 PACKAGES += cloudi_service_db_mysql
 pkg_cloudi_service_db_mysql_name = cloudi_service_db_mysql
 pkg_cloudi_service_db_mysql_description = MySQL CloudI Service
@@ -737,22 +603,6 @@ pkg_cloudi_service_db_pgsql_fetch = git
 pkg_cloudi_service_db_pgsql_repo = https://github.com/CloudI/cloudi_service_db_pgsql
 pkg_cloudi_service_db_pgsql_commit = master
 
-PACKAGES += cloudi_service_db_riak
-pkg_cloudi_service_db_riak_name = cloudi_service_db_riak
-pkg_cloudi_service_db_riak_description = Riak CloudI Service
-pkg_cloudi_service_db_riak_homepage = http://cloudi.org/
-pkg_cloudi_service_db_riak_fetch = git
-pkg_cloudi_service_db_riak_repo = https://github.com/CloudI/cloudi_service_db_riak
-pkg_cloudi_service_db_riak_commit = master
-
-PACKAGES += cloudi_service_db_tokyotyrant
-pkg_cloudi_service_db_tokyotyrant_name = cloudi_service_db_tokyotyrant
-pkg_cloudi_service_db_tokyotyrant_description = Tokyo Tyrant CloudI Service
-pkg_cloudi_service_db_tokyotyrant_homepage = http://cloudi.org/
-pkg_cloudi_service_db_tokyotyrant_fetch = git
-pkg_cloudi_service_db_tokyotyrant_repo = https://github.com/CloudI/cloudi_service_db_tokyotyrant
-pkg_cloudi_service_db_tokyotyrant_commit = master
-
 PACKAGES += cloudi_service_filesystem
 pkg_cloudi_service_filesystem_name = cloudi_service_filesystem
 pkg_cloudi_service_filesystem_description = Filesystem CloudI Service
@@ -833,14 +683,6 @@ pkg_cloudi_service_tcp_fetch = git
 pkg_cloudi_service_tcp_repo = https://github.com/CloudI/cloudi_service_tcp
 pkg_cloudi_service_tcp_commit = master
 
-PACKAGES += cloudi_service_timers
-pkg_cloudi_service_timers_name = cloudi_service_timers
-pkg_cloudi_service_timers_description = Timers CloudI Service
-pkg_cloudi_service_timers_homepage = http://cloudi.org/
-pkg_cloudi_service_timers_fetch = git
-pkg_cloudi_service_timers_repo = https://github.com/CloudI/cloudi_service_timers
-pkg_cloudi_service_timers_commit = master
-
 PACKAGES += cloudi_service_udp
 pkg_cloudi_service_udp_name = cloudi_service_udp
 pkg_cloudi_service_udp_description = UDP CloudI Service
@@ -980,9 +822,9 @@ pkg_debbie_commit = master
 PACKAGES += decimal
 pkg_decimal_name = decimal
 pkg_decimal_description = An Erlang decimal arithmetic library
-pkg_decimal_homepage = https://github.com/tim/erlang-decimal
+pkg_decimal_homepage = https://github.com/egobrain/decimal
 pkg_decimal_fetch = git
-pkg_decimal_repo = https://github.com/tim/erlang-decimal
+pkg_decimal_repo = https://github.com/egobrain/decimal
 pkg_decimal_commit = master
 
 PACKAGES += detergent
@@ -993,14 +835,6 @@ pkg_detergent_fetch = git
 pkg_detergent_repo = https://github.com/devinus/detergent
 pkg_detergent_commit = master
 
-PACKAGES += detest
-pkg_detest_name = detest
-pkg_detest_description = Tool for running tests on a cluster of erlang nodes
-pkg_detest_homepage = https://github.com/biokoda/detest
-pkg_detest_fetch = git
-pkg_detest_repo = https://github.com/biokoda/detest
-pkg_detest_commit = master
-
 PACKAGES += dh_date
 pkg_dh_date_name = dh_date
 pkg_dh_date_description = Date formatting / parsing library for erlang
@@ -1039,15 +873,7 @@ pkg_dns_description = Erlang DNS library
 pkg_dns_homepage = https://github.com/aetrion/dns_erlang
 pkg_dns_fetch = git
 pkg_dns_repo = https://github.com/aetrion/dns_erlang
-pkg_dns_commit = master
-
-PACKAGES += dnssd
-pkg_dnssd_name = dnssd
-pkg_dnssd_description = Erlang interface to Apple's Bonjour D    NS Service Discovery implementation
-pkg_dnssd_homepage = https://github.com/benoitc/dnssd_erlang
-pkg_dnssd_fetch = git
-pkg_dnssd_repo = https://github.com/benoitc/dnssd_erlang
-pkg_dnssd_commit = master
+pkg_dns_commit = main
 
 PACKAGES += dynamic_compile
 pkg_dynamic_compile_name = dynamic_compile
@@ -1113,14 +939,6 @@ pkg_edgar_fetch = git
 pkg_edgar_repo = https://github.com/crownedgrouse/edgar
 pkg_edgar_commit = master
 
-PACKAGES += edis
-pkg_edis_name = edis
-pkg_edis_description = An Erlang implementation of Redis KV Store
-pkg_edis_homepage = http://inaka.github.com/edis/
-pkg_edis_fetch = git
-pkg_edis_repo = https://github.com/inaka/edis
-pkg_edis_commit = master
-
 PACKAGES += edns
 pkg_edns_name = edns
 pkg_edns_description = Erlang/OTP DNS server
@@ -1172,10 +990,10 @@ pkg_egeoip_commit = master
 PACKAGES += ehsa
 pkg_ehsa_name = ehsa
 pkg_ehsa_description = Erlang HTTP server basic and digest authentication modules
-pkg_ehsa_homepage = https://bitbucket.org/a12n/ehsa
-pkg_ehsa_fetch = hg
-pkg_ehsa_repo = https://bitbucket.org/a12n/ehsa
-pkg_ehsa_commit = default
+pkg_ehsa_homepage = https://github.com/a12n/ehsa
+pkg_ehsa_fetch = git
+pkg_ehsa_repo = https://github.com/a12n/ehsa
+pkg_ehsa_commit = master
 
 PACKAGES += ej
 pkg_ej_name = ej
@@ -1223,7 +1041,7 @@ pkg_eleveldb_description = Erlang LevelD
 pkg_eleveldb_homepage = https://github.com/basho/eleveldb
 pkg_eleveldb_fetch = git
 pkg_eleveldb_repo = https://github.com/basho/eleveldb
-pkg_eleveldb_commit = master
+pkg_eleveldb_commit = develop
 
 PACKAGES += elixir
 pkg_elixir_name = elixir
@@ -1231,7 +1049,7 @@ pkg_elixir_description = Elixir is a dyn
 pkg_elixir_homepage = https://elixir-lang.org/
 pkg_elixir_fetch = git
 pkg_elixir_repo = https://github.com/elixir-lang/elixir
-pkg_elixir_commit = master
+pkg_elixir_commit = main
 
 PACKAGES += elli
 pkg_elli_name = elli
@@ -1239,7 +1057,7 @@ pkg_elli_description = Simple, robust an
 pkg_elli_homepage = https://github.com/elli-lib/elli
 pkg_elli_fetch = git
 pkg_elli_repo = https://github.com/elli-lib/elli
-pkg_elli_commit = master
+pkg_elli_commit = main
 
 PACKAGES += elvis
 pkg_elvis_name = elvis
@@ -1257,14 +1075,6 @@ pkg_emagick_fetch = git
 pkg_emagick_repo = https://github.com/kivra/emagick
 pkg_emagick_commit = master
 
-PACKAGES += emysql
-pkg_emysql_name = emysql
-pkg_emysql_description = Stable, pure Erlang MySQL driver.
-pkg_emysql_homepage = https://github.com/Eonblast/Emysql
-pkg_emysql_fetch = git
-pkg_emysql_repo = https://github.com/Eonblast/Emysql
-pkg_emysql_commit = master
-
 PACKAGES += enm
 pkg_enm_name = enm
 pkg_enm_description = Erlang driver for nanomsg
@@ -1353,14 +1163,6 @@ pkg_eredis_fetch = git
 pkg_eredis_repo = https://github.com/wooga/eredis
 pkg_eredis_commit = master
 
-PACKAGES += eredis_pool
-pkg_eredis_pool_name = eredis_pool
-pkg_eredis_pool_description = eredis_pool is Pool of Redis clients, using eredis and poolboy.
-pkg_eredis_pool_homepage = https://github.com/hiroeorz/eredis_pool
-pkg_eredis_pool_fetch = git
-pkg_eredis_pool_repo = https://github.com/hiroeorz/eredis_pool
-pkg_eredis_pool_commit = master
-
 PACKAGES += erl_streams
 pkg_erl_streams_name = erl_streams
 pkg_erl_streams_description = Streams in Erlang
@@ -1369,22 +1171,6 @@ pkg_erl_streams_fetch = git
 pkg_erl_streams_repo = https://github.com/epappas/erl_streams
 pkg_erl_streams_commit = master
 
-PACKAGES += erlang_cep
-pkg_erlang_cep_name = erlang_cep
-pkg_erlang_cep_description = A basic CEP package written in erlang
-pkg_erlang_cep_homepage = https://github.com/danmacklin/erlang_cep
-pkg_erlang_cep_fetch = git
-pkg_erlang_cep_repo = https://github.com/danmacklin/erlang_cep
-pkg_erlang_cep_commit = master
-
-PACKAGES += erlang_js
-pkg_erlang_js_name = erlang_js
-pkg_erlang_js_description = A linked-in driver for Erlang to Mozilla's Spidermonkey Javascript runtime.
-pkg_erlang_js_homepage = https://github.com/basho/erlang_js
-pkg_erlang_js_fetch = git
-pkg_erlang_js_repo = https://github.com/basho/erlang_js
-pkg_erlang_js_commit = master
-
 PACKAGES += erlang_localtime
 pkg_erlang_localtime_name = erlang_localtime
 pkg_erlang_localtime_description = Erlang library for conversion from one local time to another
@@ -1417,14 +1203,6 @@ pkg_erlastic_search_fetch = git
 pkg_erlastic_search_repo = https://github.com/tsloughter/erlastic_search
 pkg_erlastic_search_commit = master
 
-PACKAGES += erlasticsearch
-pkg_erlasticsearch_name = erlasticsearch
-pkg_erlasticsearch_description = Erlang thrift interface to elastic_search
-pkg_erlasticsearch_homepage = https://github.com/dieswaytoofast/erlasticsearch
-pkg_erlasticsearch_fetch = git
-pkg_erlasticsearch_repo = https://github.com/dieswaytoofast/erlasticsearch
-pkg_erlasticsearch_commit = master
-
 PACKAGES += erlbrake
 pkg_erlbrake_name = erlbrake
 pkg_erlbrake_description = Erlang Airbrake notification client
@@ -1471,7 +1249,7 @@ pkg_erldns_description = DNS server, in
 pkg_erldns_homepage = https://github.com/aetrion/erl-dns
 pkg_erldns_fetch = git
 pkg_erldns_repo = https://github.com/aetrion/erl-dns
-pkg_erldns_commit = master
+pkg_erldns_commit = main
 
 PACKAGES += erldocker
 pkg_erldocker_name = erldocker
@@ -1537,14 +1315,6 @@ pkg_erlpass_fetch = git
 pkg_erlpass_repo = https://github.com/ferd/erlpass
 pkg_erlpass_commit = master
 
-PACKAGES += erlport
-pkg_erlport_name = erlport
-pkg_erlport_description = ErlPort - connect Erlang to other languages
-pkg_erlport_homepage = https://github.com/hdima/erlport
-pkg_erlport_fetch = git
-pkg_erlport_repo = https://github.com/hdima/erlport
-pkg_erlport_commit = master
-
 PACKAGES += erlsh
 pkg_erlsh_name = erlsh
 pkg_erlsh_description = Erlang shell tools
@@ -1617,14 +1387,6 @@ pkg_erserve_fetch = git
 pkg_erserve_repo = https://github.com/del/erserve
 pkg_erserve_commit = master
 
-PACKAGES += erwa
-pkg_erwa_name = erwa
-pkg_erwa_description = A WAMP router and client written in Erlang.
-pkg_erwa_homepage = https://github.com/bwegh/erwa
-pkg_erwa_fetch = git
-pkg_erwa_repo = https://github.com/bwegh/erwa
-pkg_erwa_commit = master
-
 PACKAGES += escalus
 pkg_escalus_name = escalus
 pkg_escalus_description = An XMPP client library in Erlang for conveniently testing XMPP servers
@@ -1753,14 +1515,6 @@ pkg_exs1024_fetch = git
 pkg_exs1024_repo = https://github.com/jj1bdx/exs1024
 pkg_exs1024_commit = master
 
-PACKAGES += exs64
-pkg_exs64_name = exs64
-pkg_exs64_description = Xorshift64star pseudo random number generator for Erlang.
-pkg_exs64_homepage = https://github.com/jj1bdx/exs64
-pkg_exs64_fetch = git
-pkg_exs64_repo = https://github.com/jj1bdx/exs64
-pkg_exs64_commit = master
-
 PACKAGES += exsplus116
 pkg_exsplus116_name = exsplus116
 pkg_exsplus116_description = Xorshift116plus for Erlang
@@ -1769,22 +1523,6 @@ pkg_exsplus116_fetch = git
 pkg_exsplus116_repo = https://github.com/jj1bdx/exsplus116
 pkg_exsplus116_commit = master
 
-PACKAGES += exsplus128
-pkg_exsplus128_name = exsplus128
-pkg_exsplus128_description = Xorshift128plus pseudo random number generator for Erlang.
-pkg_exsplus128_homepage = https://github.com/jj1bdx/exsplus128
-pkg_exsplus128_fetch = git
-pkg_exsplus128_repo = https://github.com/jj1bdx/exsplus128
-pkg_exsplus128_commit = master
-
-PACKAGES += ezmq
-pkg_ezmq_name = ezmq
-pkg_ezmq_description = zMQ implemented in Erlang
-pkg_ezmq_homepage = https://github.com/RoadRunnr/ezmq
-pkg_ezmq_fetch = git
-pkg_ezmq_repo = https://github.com/RoadRunnr/ezmq
-pkg_ezmq_commit = master
-
 PACKAGES += ezmtp
 pkg_ezmtp_name = ezmtp
 pkg_ezmtp_description = ZMTP protocol in pure Erlang.
@@ -1857,14 +1595,6 @@ pkg_folsom_cowboy_fetch = git
 pkg_folsom_cowboy_repo = https://github.com/boundary/folsom_cowboy
 pkg_folsom_cowboy_commit = master
 
-PACKAGES += folsomite
-pkg_folsomite_name = folsomite
-pkg_folsomite_description = blow up your graphite / riemann server with folsom metrics
-pkg_folsomite_homepage = https://github.com/campanja/folsomite
-pkg_folsomite_fetch = git
-pkg_folsomite_repo = https://github.com/campanja/folsomite
-pkg_folsomite_commit = master
-
 PACKAGES += fs
 pkg_fs_name = fs
 pkg_fs_description = Erlang FileSystem Listener
@@ -2041,14 +1771,6 @@ pkg_gitty_fetch = git
 pkg_gitty_repo = https://github.com/maxlapshin/gitty
 pkg_gitty_commit = master
 
-PACKAGES += gold_fever
-pkg_gold_fever_name = gold_fever
-pkg_gold_fever_description = A Treasure Hunt for Erlangers
-pkg_gold_fever_homepage = https://github.com/inaka/gold_fever
-pkg_gold_fever_fetch = git
-pkg_gold_fever_repo = https://github.com/inaka/gold_fever
-pkg_gold_fever_commit = master
-
 PACKAGES += gpb
 pkg_gpb_name = gpb
 pkg_gpb_description = A Google Protobuf implementation for Erlang
@@ -2097,14 +1819,6 @@ pkg_gun_fetch = git
 pkg_gun_repo = https://github.com/ninenines/gun
 pkg_gun_commit = master
 
-PACKAGES += gut
-pkg_gut_name = gut
-pkg_gut_description = gut is a template printing, aka scaffolding, tool for Erlang. Like rails generate or yeoman
-pkg_gut_homepage = https://github.com/unbalancedparentheses/gut
-pkg_gut_fetch = git
-pkg_gut_repo = https://github.com/unbalancedparentheses/gut
-pkg_gut_commit = master
-
 PACKAGES += hackney
 pkg_hackney_name = hackney
 pkg_hackney_description = simple HTTP client in Erlang
@@ -2121,14 +1835,6 @@ pkg_hamcrest_fetch = git
 pkg_hamcrest_repo = https://github.com/hyperthunk/hamcrest-erlang
 pkg_hamcrest_commit = master
 
-PACKAGES += hanoidb
-pkg_hanoidb_name = hanoidb
-pkg_hanoidb_description = Erlang LSM BTree Storage
-pkg_hanoidb_homepage = https://github.com/krestenkrab/hanoidb
-pkg_hanoidb_fetch = git
-pkg_hanoidb_repo = https://github.com/krestenkrab/hanoidb
-pkg_hanoidb_commit = master
-
 PACKAGES += hottub
 pkg_hottub_name = hottub
 pkg_hottub_description = Permanent Erlang Worker Pool
@@ -2177,22 +1883,6 @@ pkg_idna_fetch = git
 pkg_idna_repo = https://github.com/benoitc/erlang-idna
 pkg_idna_commit = master
 
-PACKAGES += ierlang
-pkg_ierlang_name = ierlang
-pkg_ierlang_description = An Erlang language kernel for IPython.
-pkg_ierlang_homepage = https://github.com/robbielynch/ierlang
-pkg_ierlang_fetch = git
-pkg_ierlang_repo = https://github.com/robbielynch/ierlang
-pkg_ierlang_commit = master
-
-PACKAGES += iota
-pkg_iota_name = iota
-pkg_iota_description = iota (Inter-dependency Objective Testing Apparatus) - a tool to enforce clean separation of responsibilities in Erlang code
-pkg_iota_homepage = https://github.com/jpgneves/iota
-pkg_iota_fetch = git
-pkg_iota_repo = https://github.com/jpgneves/iota
-pkg_iota_commit = master
-
 PACKAGES += irc_lib
 pkg_irc_lib_name = irc_lib
 pkg_irc_lib_description = Erlang irc client library
@@ -2233,14 +1923,6 @@ pkg_jamdb_sybase_fetch = git
 pkg_jamdb_sybase_repo = https://github.com/erlangbureau/jamdb_sybase
 pkg_jamdb_sybase_commit = master
 
-PACKAGES += jerg
-pkg_jerg_name = jerg
-pkg_jerg_description = JSON Schema to Erlang Records Generator
-pkg_jerg_homepage = https://github.com/ddossot/jerg
-pkg_jerg_fetch = git
-pkg_jerg_repo = https://github.com/ddossot/jerg
-pkg_jerg_commit = master
-
 PACKAGES += jesse
 pkg_jesse_name = jesse
 pkg_jesse_description = jesse (JSon Schema Erlang) is an implementation of a json schema validator for Erlang.
@@ -2267,10 +1949,10 @@ pkg_jiffy_v_commit = master
 
 PACKAGES += jobs
 pkg_jobs_name = jobs
-pkg_jobs_description = a Job scheduler for load regulation
-pkg_jobs_homepage = https://github.com/esl/jobs
+pkg_jobs_description = Job scheduler for load regulation
+pkg_jobs_homepage = https://github.com/uwiger/jobs
 pkg_jobs_fetch = git
-pkg_jobs_repo = https://github.com/esl/jobs
+pkg_jobs_repo = https://github.com/uwiger/jobs
 pkg_jobs_commit = master
 
 PACKAGES += joxa
@@ -2281,14 +1963,6 @@ pkg_joxa_fetch = git
 pkg_joxa_repo = https://github.com/joxa/joxa
 pkg_joxa_commit = master
 
-PACKAGES += json
-pkg_json_name = json
-pkg_json_description = a high level json library for erlang (17.0+)
-pkg_json_homepage = https://github.com/talentdeficit/json
-pkg_json_fetch = git
-pkg_json_repo = https://github.com/talentdeficit/json
-pkg_json_commit = master
-
 PACKAGES += json_rec
 pkg_json_rec_name = json_rec
 pkg_json_rec_description = JSON to erlang record
@@ -2305,14 +1979,6 @@ pkg_jsone_fetch = git
 pkg_jsone_repo = https://github.com/sile/jsone.git
 pkg_jsone_commit = master
 
-PACKAGES += jsonerl
-pkg_jsonerl_name = jsonerl
-pkg_jsonerl_description = yet another but slightly different erlang <-> json encoder/decoder
-pkg_jsonerl_homepage = https://github.com/lambder/jsonerl
-pkg_jsonerl_fetch = git
-pkg_jsonerl_repo = https://github.com/lambder/jsonerl
-pkg_jsonerl_commit = master
-
 PACKAGES += jsonpath
 pkg_jsonpath_name = jsonpath
 pkg_jsonpath_description = Fast Erlang JSON data retrieval and updates via javascript-like notation
@@ -2337,20 +2003,12 @@ pkg_jsx_fetch = git
 pkg_jsx_repo = https://github.com/talentdeficit/jsx
 pkg_jsx_commit = main
 
-PACKAGES += kafka
-pkg_kafka_name = kafka
-pkg_kafka_description = Kafka consumer and producer in Erlang
-pkg_kafka_homepage = https://github.com/wooga/kafka-erlang
-pkg_kafka_fetch = git
-pkg_kafka_repo = https://github.com/wooga/kafka-erlang
-pkg_kafka_commit = master
-
 PACKAGES += kafka_protocol
 pkg_kafka_protocol_name = kafka_protocol
 pkg_kafka_protocol_description = Kafka protocol Erlang library
-pkg_kafka_protocol_homepage = https://github.com/klarna/kafka_protocol
+pkg_kafka_protocol_homepage = https://github.com/kafka4beam/kafka_protocol
 pkg_kafka_protocol_fetch = git
-pkg_kafka_protocol_repo = https://github.com/klarna/kafka_protocol.git
+pkg_kafka_protocol_repo = https://github.com/kafka4beam/kafka_protocol
 pkg_kafka_protocol_commit = master
 
 PACKAGES += kai
@@ -2369,14 +2027,6 @@ pkg_katja_fetch = git
 pkg_katja_repo = https://github.com/nifoc/katja
 pkg_katja_commit = master
 
-PACKAGES += kdht
-pkg_kdht_name = kdht
-pkg_kdht_description = kdht is an erlang DHT implementation
-pkg_kdht_homepage = https://github.com/kevinlynx/kdht
-pkg_kdht_fetch = git
-pkg_kdht_repo = https://github.com/kevinlynx/kdht
-pkg_kdht_commit = master
-
 PACKAGES += key2value
 pkg_key2value_name = key2value
 pkg_key2value_description = Erlang 2-way map
@@ -2399,7 +2049,7 @@ pkg_kinetic_description = Erlang Kinesis
 pkg_kinetic_homepage = https://github.com/AdRoll/kinetic
 pkg_kinetic_fetch = git
 pkg_kinetic_repo = https://github.com/AdRoll/kinetic
-pkg_kinetic_commit = master
+pkg_kinetic_commit = main
 
 PACKAGES += kjell
 pkg_kjell_name = kjell
@@ -2457,14 +2107,6 @@ pkg_lager_fetch = git
 pkg_lager_repo = https://github.com/erlang-lager/lager
 pkg_lager_commit = master
 
-PACKAGES += lager_amqp_backend
-pkg_lager_amqp_backend_name = lager_amqp_backend
-pkg_lager_amqp_backend_description = AMQP RabbitMQ Lager backend
-pkg_lager_amqp_backend_homepage = https://github.com/jbrisbin/lager_amqp_backend
-pkg_lager_amqp_backend_fetch = git
-pkg_lager_amqp_backend_repo = https://github.com/jbrisbin/lager_amqp_backend
-pkg_lager_amqp_backend_commit = master
-
 PACKAGES += lager_syslog
 pkg_lager_syslog_name = lager_syslog
 pkg_lager_syslog_description = Syslog backend for lager
@@ -2473,22 +2115,6 @@ pkg_lager_syslog_fetch = git
 pkg_lager_syslog_repo = https://github.com/erlang-lager/lager_syslog
 pkg_lager_syslog_commit = master
 
-PACKAGES += lambdapad
-pkg_lambdapad_name = lambdapad
-pkg_lambdapad_description = Static site generator using Erlang. Yes, Erlang.
-pkg_lambdapad_homepage = https://github.com/gar1t/lambdapad
-pkg_lambdapad_fetch = git
-pkg_lambdapad_repo = https://github.com/gar1t/lambdapad
-pkg_lambdapad_commit = master
-
-PACKAGES += lasp
-pkg_lasp_name = lasp
-pkg_lasp_description = A Language for Distributed, Eventually Consistent Computations
-pkg_lasp_homepage = http://lasp-lang.org/
-pkg_lasp_fetch = git
-pkg_lasp_repo = https://github.com/lasp-lang/lasp
-pkg_lasp_commit = master
-
 PACKAGES += lasse
 pkg_lasse_name = lasse
 pkg_lasse_description = SSE handler for Cowboy
@@ -2505,14 +2131,6 @@ pkg_ldap_fetch = git
 pkg_ldap_repo = https://github.com/spawnproc/ldap
 pkg_ldap_commit = master
 
-PACKAGES += lethink
-pkg_lethink_name = lethink
-pkg_lethink_description = erlang driver for rethinkdb
-pkg_lethink_homepage = https://github.com/taybin/lethink
-pkg_lethink_fetch = git
-pkg_lethink_repo = https://github.com/taybin/lethink
-pkg_lethink_commit = master
-
 PACKAGES += lfe
 pkg_lfe_name = lfe
 pkg_lfe_description = Lisp Flavoured Erlang (LFE)
@@ -2521,14 +2139,6 @@ pkg_lfe_fetch = git
 pkg_lfe_repo = https://github.com/rvirding/lfe
 pkg_lfe_commit = master
 
-PACKAGES += ling
-pkg_ling_name = ling
-pkg_ling_description = Erlang on Xen
-pkg_ling_homepage = https://github.com/cloudozer/ling
-pkg_ling_fetch = git
-pkg_ling_repo = https://github.com/cloudozer/ling
-pkg_ling_commit = master
-
 PACKAGES += live
 pkg_live_name = live
 pkg_live_description = Automated module and configuration reloader.
@@ -2537,14 +2147,6 @@ pkg_live_fetch = git
 pkg_live_repo = https://github.com/ninenines/live
 pkg_live_commit = master
 
-PACKAGES += lmq
-pkg_lmq_name = lmq
-pkg_lmq_description = Lightweight Message Queue
-pkg_lmq_homepage = https://github.com/iij/lmq
-pkg_lmq_fetch = git
-pkg_lmq_repo = https://github.com/iij/lmq
-pkg_lmq_commit = master
-
 PACKAGES += locker
 pkg_locker_name = locker
 pkg_locker_description = Atomic distributed 'check and set' for short-lived keys
@@ -2593,14 +2195,6 @@ pkg_luerl_fetch = git
 pkg_luerl_repo = https://github.com/rvirding/luerl
 pkg_luerl_commit = develop
 
-PACKAGES += luwak
-pkg_luwak_name = luwak
-pkg_luwak_description = Large-object storage interface for Riak
-pkg_luwak_homepage = https://github.com/basho/luwak
-pkg_luwak_fetch = git
-pkg_luwak_repo = https://github.com/basho/luwak
-pkg_luwak_commit = master
-
 PACKAGES += lux
 pkg_lux_name = lux
 pkg_lux_description = Lux (LUcid eXpect scripting) simplifies test automation and provides an Expect-style execution of commands
@@ -2609,14 +2203,6 @@ pkg_lux_fetch = git
 pkg_lux_repo = https://github.com/hawk/lux
 pkg_lux_commit = master
 
-PACKAGES += machi
-pkg_machi_name = machi
-pkg_machi_description = Machi file store
-pkg_machi_homepage = https://github.com/basho/machi
-pkg_machi_fetch = git
-pkg_machi_repo = https://github.com/basho/machi
-pkg_machi_commit = master
-
 PACKAGES += mad
 pkg_mad_name = mad
 pkg_mad_description = Small and Fast Rebar Replacement
@@ -2641,30 +2227,6 @@ pkg_mavg_fetch = git
 pkg_mavg_repo = https://github.com/EchoTeam/mavg
 pkg_mavg_commit = master
 
-PACKAGES += mc_erl
-pkg_mc_erl_name = mc_erl
-pkg_mc_erl_description = mc-erl is a server for Minecraft 1.4.7 written in Erlang.
-pkg_mc_erl_homepage = https://github.com/clonejo/mc-erl
-pkg_mc_erl_fetch = git
-pkg_mc_erl_repo = https://github.com/clonejo/mc-erl
-pkg_mc_erl_commit = master
-
-PACKAGES += mcd
-pkg_mcd_name = mcd
-pkg_mcd_description = Fast memcached protocol client in pure Erlang
-pkg_mcd_homepage = https://github.com/EchoTeam/mcd
-pkg_mcd_fetch = git
-pkg_mcd_repo = https://github.com/EchoTeam/mcd
-pkg_mcd_commit = master
-
-PACKAGES += mcerlang
-pkg_mcerlang_name = mcerlang
-pkg_mcerlang_description = The McErlang model checker for Erlang
-pkg_mcerlang_homepage = https://github.com/fredlund/McErlang
-pkg_mcerlang_fetch = git
-pkg_mcerlang_repo = https://github.com/fredlund/McErlang
-pkg_mcerlang_commit = master
-
 PACKAGES += meck
 pkg_meck_name = meck
 pkg_meck_description = A mocking library for Erlang
@@ -2681,22 +2243,6 @@ pkg_mekao_fetch = git
 pkg_mekao_repo = https://github.com/ddosia/mekao
 pkg_mekao_commit = master
 
-PACKAGES += memo
-pkg_memo_name = memo
-pkg_memo_description = Erlang memoization server
-pkg_memo_homepage = https://github.com/tuncer/memo
-pkg_memo_fetch = git
-pkg_memo_repo = https://github.com/tuncer/memo
-pkg_memo_commit = master
-
-PACKAGES += merge_index
-pkg_merge_index_name = merge_index
-pkg_merge_index_description = MergeIndex is an Erlang library for storing ordered sets on disk. It is very similar to an SSTable (in Google's Bigtable) or an HFile (in Hadoop).
-pkg_merge_index_homepage = https://github.com/basho/merge_index
-pkg_merge_index_fetch = git
-pkg_merge_index_repo = https://github.com/basho/merge_index
-pkg_merge_index_commit = master
-
 PACKAGES += merl
 pkg_merl_name = merl
 pkg_merl_description = Metaprogramming in Erlang
@@ -2727,7 +2273,7 @@ pkg_mixer_description = Mix in functions
 pkg_mixer_homepage = https://github.com/chef/mixer
 pkg_mixer_fetch = git
 pkg_mixer_repo = https://github.com/chef/mixer
-pkg_mixer_commit = master
+pkg_mixer_commit = main
 
 PACKAGES += mochiweb
 pkg_mochiweb_name = mochiweb
@@ -2857,14 +2403,6 @@ pkg_neotoma_fetch = git
 pkg_neotoma_repo = https://github.com/seancribbs/neotoma
 pkg_neotoma_commit = master
 
-PACKAGES += newrelic
-pkg_newrelic_name = newrelic
-pkg_newrelic_description = Erlang library for sending metrics to New Relic
-pkg_newrelic_homepage = https://github.com/wooga/newrelic-erlang
-pkg_newrelic_fetch = git
-pkg_newrelic_repo = https://github.com/wooga/newrelic-erlang
-pkg_newrelic_commit = master
-
 PACKAGES += nifty
 pkg_nifty_name = nifty
 pkg_nifty_description = Erlang NIF wrapper generator
@@ -2881,22 +2419,6 @@ pkg_nitrogen_core_fetch = git
 pkg_nitrogen_core_repo = https://github.com/nitrogen/nitrogen_core
 pkg_nitrogen_core_commit = master
 
-PACKAGES += nkbase
-pkg_nkbase_name = nkbase
-pkg_nkbase_description = NkBASE distributed database
-pkg_nkbase_homepage = https://github.com/Nekso/nkbase
-pkg_nkbase_fetch = git
-pkg_nkbase_repo = https://github.com/Nekso/nkbase
-pkg_nkbase_commit = develop
-
-PACKAGES += nkdocker
-pkg_nkdocker_name = nkdocker
-pkg_nkdocker_description = Erlang Docker client
-pkg_nkdocker_homepage = https://github.com/Nekso/nkdocker
-pkg_nkdocker_fetch = git
-pkg_nkdocker_repo = https://github.com/Nekso/nkdocker
-pkg_nkdocker_commit = master
-
 PACKAGES += nkpacket
 pkg_nkpacket_name = nkpacket
 pkg_nkpacket_description = Generic Erlang transport layer
@@ -2935,7 +2457,7 @@ pkg_oauth_description = An Erlang OAuth
 pkg_oauth_homepage = https://github.com/tim/erlang-oauth
 pkg_oauth_fetch = git
 pkg_oauth_repo = https://github.com/tim/erlang-oauth
-pkg_oauth_commit = master
+pkg_oauth_commit = main
 
 PACKAGES += oauth2
 pkg_oauth2_name = oauth2
@@ -2961,22 +2483,6 @@ pkg_octopus_fetch = git
 pkg_octopus_repo = https://github.com/erlangbureau/octopus
 pkg_octopus_commit = master
 
-PACKAGES += of_protocol
-pkg_of_protocol_name = of_protocol
-pkg_of_protocol_description = OpenFlow Protocol Library for Erlang
-pkg_of_protocol_homepage = https://github.com/FlowForwarding/of_protocol
-pkg_of_protocol_fetch = git
-pkg_of_protocol_repo = https://github.com/FlowForwarding/of_protocol
-pkg_of_protocol_commit = master
-
-PACKAGES += opencouch
-pkg_opencouch_name = couch
-pkg_opencouch_description = A embeddable document oriented database compatible with Apache CouchDB
-pkg_opencouch_homepage = https://github.com/benoitc/opencouch
-pkg_opencouch_fetch = git
-pkg_opencouch_repo = https://github.com/benoitc/opencouch
-pkg_opencouch_commit = master
-
 PACKAGES += openflow
 pkg_openflow_name = openflow
 pkg_openflow_description = An OpenFlow controller written in pure erlang
@@ -3063,7 +2569,7 @@ pkg_pgo_description = Erlang Postgres cl
 pkg_pgo_homepage = https://github.com/erleans/pgo.git
 pkg_pgo_fetch = git
 pkg_pgo_repo = https://github.com/erleans/pgo.git
-pkg_pgo_commit = master
+pkg_pgo_commit = main
 
 PACKAGES += pgsql
 pkg_pgsql_name = pgsql
@@ -3097,14 +2603,6 @@ pkg_plain_fsm_fetch = git
 pkg_plain_fsm_repo = https://github.com/uwiger/plain_fsm
 pkg_plain_fsm_commit = master
 
-PACKAGES += plumtree
-pkg_plumtree_name = plumtree
-pkg_plumtree_description = Epidemic Broadcast Trees
-pkg_plumtree_homepage = https://github.com/helium/plumtree
-pkg_plumtree_fetch = git
-pkg_plumtree_repo = https://github.com/helium/plumtree
-pkg_plumtree_commit = master
-
 PACKAGES += pmod_transform
 pkg_pmod_transform_name = pmod_transform
 pkg_pmod_transform_description = Parse transform for parameterized modules
@@ -3217,14 +2715,6 @@ pkg_purity_fetch = git
 pkg_purity_repo = https://github.com/mpitid/purity
 pkg_purity_commit = master
 
-PACKAGES += push_service
-pkg_push_service_name = push_service
-pkg_push_service_description = Push service
-pkg_push_service_homepage = https://github.com/hairyhum/push_service
-pkg_push_service_fetch = git
-pkg_push_service_repo = https://github.com/hairyhum/push_service
-pkg_push_service_commit = master
-
 PACKAGES += qdate
 pkg_qdate_name = qdate
 pkg_qdate_description = Date, time, and timezone parsing, formatting, and conversion for Erlang.
@@ -3257,14 +2747,6 @@ pkg_quickrand_fetch = git
 pkg_quickrand_repo = https://github.com/okeuday/quickrand
 pkg_quickrand_commit = master
 
-PACKAGES += rabbit
-pkg_rabbit_name = rabbit
-pkg_rabbit_description = RabbitMQ Server
-pkg_rabbit_homepage = https://www.rabbitmq.com/
-pkg_rabbit_fetch = git
-pkg_rabbit_repo = https://github.com/rabbitmq/rabbitmq-server.git
-pkg_rabbit_commit = master
-
 PACKAGES += rabbit_exchange_type_riak
 pkg_rabbit_exchange_type_riak_name = rabbit_exchange_type_riak
 pkg_rabbit_exchange_type_riak_description = Custom RabbitMQ exchange type for sticking messages in Riak
@@ -3289,14 +2771,6 @@ pkg_radierl_fetch = git
 pkg_radierl_repo = https://github.com/vances/radierl
 pkg_radierl_commit = master
 
-PACKAGES += rafter
-pkg_rafter_name = rafter
-pkg_rafter_description = An Erlang library application which implements the Raft consensus protocol
-pkg_rafter_homepage = https://github.com/andrewjstone/rafter
-pkg_rafter_fetch = git
-pkg_rafter_repo = https://github.com/andrewjstone/rafter
-pkg_rafter_commit = master
-
 PACKAGES += ranch
 pkg_ranch_name = ranch
 pkg_ranch_description = Socket acceptor pool for TCP protocols.
@@ -3313,13 +2787,13 @@ pkg_rbeacon_fetch = git
 pkg_rbeacon_repo = https://github.com/refuge/rbeacon
 pkg_rbeacon_commit = master
 
-PACKAGES += rebar
-pkg_rebar_name = rebar
-pkg_rebar_description = Erlang build tool that makes it easy to compile and test Erlang applications, port drivers and releases.
-pkg_rebar_homepage = http://www.rebar3.org
-pkg_rebar_fetch = git
-pkg_rebar_repo = https://github.com/rebar/rebar3
-pkg_rebar_commit = master
+PACKAGES += re2
+pkg_re2_name = re2
+pkg_re2_description = Erlang NIF bindings for RE2 regex library
+pkg_re2_homepage = https://github.com/dukesoferl/re2
+pkg_re2_fetch = git
+pkg_re2_repo = https://github.com/dukesoferl/re2
+pkg_re2_commit = master
 
 PACKAGES += rebus
 pkg_rebus_name = rebus
@@ -3417,21 +2891,13 @@ pkg_rfc4627_jsonrpc_fetch = git
 pkg_rfc4627_jsonrpc_repo = https://github.com/tonyg/erlang-rfc4627
 pkg_rfc4627_jsonrpc_commit = master
 
-PACKAGES += riak_control
-pkg_riak_control_name = riak_control
-pkg_riak_control_description = Webmachine-based administration interface for Riak.
-pkg_riak_control_homepage = https://github.com/basho/riak_control
-pkg_riak_control_fetch = git
-pkg_riak_control_repo = https://github.com/basho/riak_control
-pkg_riak_control_commit = master
-
 PACKAGES += riak_core
 pkg_riak_core_name = riak_core
 pkg_riak_core_description = Distributed systems infrastructure used by Riak.
 pkg_riak_core_homepage = https://github.com/basho/riak_core
 pkg_riak_core_fetch = git
 pkg_riak_core_repo = https://github.com/basho/riak_core
-pkg_riak_core_commit = master
+pkg_riak_core_commit = develop
 
 PACKAGES += riak_dt
 pkg_riak_dt_name = riak_dt
@@ -3447,7 +2913,7 @@ pkg_riak_ensemble_description = Multi-Pa
 pkg_riak_ensemble_homepage = https://github.com/basho/riak_ensemble
 pkg_riak_ensemble_fetch = git
 pkg_riak_ensemble_repo = https://github.com/basho/riak_ensemble
-pkg_riak_ensemble_commit = master
+pkg_riak_ensemble_commit = develop
 
 PACKAGES += riak_kv
 pkg_riak_kv_name = riak_kv
@@ -3455,15 +2921,7 @@ pkg_riak_kv_description = Riak Key/Value
 pkg_riak_kv_homepage = https://github.com/basho/riak_kv
 pkg_riak_kv_fetch = git
 pkg_riak_kv_repo = https://github.com/basho/riak_kv
-pkg_riak_kv_commit = master
-
-PACKAGES += riak_pg
-pkg_riak_pg_name = riak_pg
-pkg_riak_pg_description = Distributed process groups with riak_core.
-pkg_riak_pg_homepage = https://github.com/cmeiklejohn/riak_pg
-pkg_riak_pg_fetch = git
-pkg_riak_pg_repo = https://github.com/cmeiklejohn/riak_pg
-pkg_riak_pg_commit = master
+pkg_riak_kv_commit = develop
 
 PACKAGES += riak_pipe
 pkg_riak_pipe_name = riak_pipe
@@ -3471,7 +2929,7 @@ pkg_riak_pipe_description = Riak Pipelin
 pkg_riak_pipe_homepage = https://github.com/basho/riak_pipe
 pkg_riak_pipe_fetch = git
 pkg_riak_pipe_repo = https://github.com/basho/riak_pipe
-pkg_riak_pipe_commit = master
+pkg_riak_pipe_commit = develop
 
 PACKAGES += riak_sysmon
 pkg_riak_sysmon_name = riak_sysmon
@@ -3481,14 +2939,6 @@ pkg_riak_sysmon_fetch = git
 pkg_riak_sysmon_repo = https://github.com/basho/riak_sysmon
 pkg_riak_sysmon_commit = master
 
-PACKAGES += riak_test
-pkg_riak_test_name = riak_test
-pkg_riak_test_description = I'm in your cluster, testing your riaks
-pkg_riak_test_homepage = https://github.com/basho/riak_test
-pkg_riak_test_fetch = git
-pkg_riak_test_repo = https://github.com/basho/riak_test
-pkg_riak_test_commit = master
-
 PACKAGES += riakc
 pkg_riakc_name = riakc
 pkg_riakc_description = Erlang clients for Riak.
@@ -3497,38 +2947,6 @@ pkg_riakc_fetch = git
 pkg_riakc_repo = https://github.com/basho/riak-erlang-client
 pkg_riakc_commit = master
 
-PACKAGES += riakhttpc
-pkg_riakhttpc_name = riakhttpc
-pkg_riakhttpc_description = Riak Erlang client using the HTTP interface
-pkg_riakhttpc_homepage = https://github.com/basho/riak-erlang-http-client
-pkg_riakhttpc_fetch = git
-pkg_riakhttpc_repo = https://github.com/basho/riak-erlang-http-client
-pkg_riakhttpc_commit = master
-
-PACKAGES += riaknostic
-pkg_riaknostic_name = riaknostic
-pkg_riaknostic_description = A diagnostic tool for Riak installations, to find common errors asap
-pkg_riaknostic_homepage = https://github.com/basho/riaknostic
-pkg_riaknostic_fetch = git
-pkg_riaknostic_repo = https://github.com/basho/riaknostic
-pkg_riaknostic_commit = master
-
-PACKAGES += riakpool
-pkg_riakpool_name = riakpool
-pkg_riakpool_description = erlang riak client pool
-pkg_riakpool_homepage = https://github.com/dweldon/riakpool
-pkg_riakpool_fetch = git
-pkg_riakpool_repo = https://github.com/dweldon/riakpool
-pkg_riakpool_commit = master
-
-PACKAGES += rivus_cep
-pkg_rivus_cep_name = rivus_cep
-pkg_rivus_cep_description = Complex event processing in Erlang
-pkg_rivus_cep_homepage = https://github.com/vascokk/rivus_cep
-pkg_rivus_cep_fetch = git
-pkg_rivus_cep_repo = https://github.com/vascokk/rivus_cep
-pkg_rivus_cep_commit = master
-
 PACKAGES += rlimit
 pkg_rlimit_name = rlimit
 pkg_rlimit_description = Magnus Klaar's rate limiter code from etorrent
@@ -3561,14 +2979,6 @@ pkg_seestar_fetch = git
 pkg_seestar_repo = https://github.com/iamaleksey/seestar
 pkg_seestar_commit = master
 
-PACKAGES += service
-pkg_service_name = service
-pkg_service_description = A minimal Erlang behavior for creating CloudI internal services
-pkg_service_homepage = http://cloudi.org/
-pkg_service_fetch = git
-pkg_service_repo = https://github.com/CloudI/service
-pkg_service_commit = master
-
 PACKAGES += setup
 pkg_setup_name = setup
 pkg_setup_description = Generic setup utility for Erlang-based systems
@@ -3623,7 +3033,7 @@ pkg_sidejob_description = Parallel worke
 pkg_sidejob_homepage = https://github.com/basho/sidejob
 pkg_sidejob_fetch = git
 pkg_sidejob_repo = https://github.com/basho/sidejob
-pkg_sidejob_commit = master
+pkg_sidejob_commit = develop
 
 PACKAGES += sieve
 pkg_sieve_name = sieve
@@ -3633,14 +3043,6 @@ pkg_sieve_fetch = git
 pkg_sieve_repo = https://github.com/benoitc/sieve
 pkg_sieve_commit = master
 
-PACKAGES += sighandler
-pkg_sighandler_name = sighandler
-pkg_sighandler_description = Handle UNIX signals in Er    lang
-pkg_sighandler_homepage = https://github.com/jkingsbery/sighandler
-pkg_sighandler_fetch = git
-pkg_sighandler_repo = https://github.com/jkingsbery/sighandler
-pkg_sighandler_commit = master
-
 PACKAGES += simhash
 pkg_simhash_name = simhash
 pkg_simhash_description = Simhashing for Erlang -- hashing algorithm to find near-duplicates in binary data.
@@ -3681,14 +3083,6 @@ pkg_slack_fetch = git
 pkg_slack_repo = https://github.com/DonBranson/slack.git
 pkg_slack_commit = master
 
-PACKAGES += smother
-pkg_smother_name = smother
-pkg_smother_description = Extended code coverage metrics for Erlang.
-pkg_smother_homepage = https://ramsay-t.github.io/Smother/
-pkg_smother_fetch = git
-pkg_smother_repo = https://github.com/ramsay-t/Smother
-pkg_smother_commit = master
-
 PACKAGES += snappyer
 pkg_snappyer_name = snappyer
 pkg_snappyer_description = Snappy as nif for Erlang
@@ -3705,14 +3099,6 @@ pkg_social_fetch = git
 pkg_social_repo = https://github.com/dvv/social
 pkg_social_commit = master
 
-PACKAGES += spapi_router
-pkg_spapi_router_name = spapi_router
-pkg_spapi_router_description = Partially-connected Erlang clustering
-pkg_spapi_router_homepage = https://github.com/spilgames/spapi-router
-pkg_spapi_router_fetch = git
-pkg_spapi_router_repo = https://github.com/spilgames/spapi-router
-pkg_spapi_router_commit = master
-
 PACKAGES += sqerl
 pkg_sqerl_name = sqerl
 pkg_sqerl_description = An Erlang-flavoured SQL DSL
@@ -3753,14 +3139,6 @@ pkg_statebox_fetch = git
 pkg_statebox_repo = https://github.com/mochi/statebox
 pkg_statebox_commit = master
 
-PACKAGES += statebox_riak
-pkg_statebox_riak_name = statebox_riak
-pkg_statebox_riak_description = Convenience library that makes it easier to use statebox with riak, extracted from best practices in our production code at Mochi Media.
-pkg_statebox_riak_homepage = https://github.com/mochi/statebox_riak
-pkg_statebox_riak_fetch = git
-pkg_statebox_riak_repo = https://github.com/mochi/statebox_riak
-pkg_statebox_riak_commit = master
-
 PACKAGES += statman
 pkg_statman_name = statman
 pkg_statman_description = Efficiently collect massive volumes of metrics inside the Erlang VM
@@ -3793,14 +3171,6 @@ pkg_stockdb_fetch = git
 pkg_stockdb_repo = https://github.com/maxlapshin/stockdb
 pkg_stockdb_commit = master
 
-PACKAGES += stripe
-pkg_stripe_name = stripe
-pkg_stripe_description = Erlang interface to the stripe.com API
-pkg_stripe_homepage = https://github.com/mattsta/stripe-erlang
-pkg_stripe_fetch = git
-pkg_stripe_repo = https://github.com/mattsta/stripe-erlang
-pkg_stripe_commit = v1
-
 PACKAGES += subproc
 pkg_subproc_name = subproc
 pkg_subproc_description = unix subprocess manager with {active,once|false} modes
@@ -3817,14 +3187,6 @@ pkg_supervisor3_fetch = git
 pkg_supervisor3_repo = https://github.com/klarna/supervisor3.git
 pkg_supervisor3_commit = master
 
-PACKAGES += surrogate
-pkg_surrogate_name = surrogate
-pkg_surrogate_description = Proxy server written in erlang. Supports reverse proxy load balancing and forward proxy with http (including CONNECT), socks4, socks5, and transparent proxy modes.
-pkg_surrogate_homepage = https://github.com/skruger/Surrogate
-pkg_surrogate_fetch = git
-pkg_surrogate_repo = https://github.com/skruger/Surrogate
-pkg_surrogate_commit = master
-
 PACKAGES += swab
 pkg_swab_name = swab
 pkg_swab_description = General purpose buffer handling module
@@ -3905,14 +3267,6 @@ pkg_tempo_fetch = git
 pkg_tempo_repo = https://github.com/selectel/tempo
 pkg_tempo_commit = master
 
-PACKAGES += ticktick
-pkg_ticktick_name = ticktick
-pkg_ticktick_description = Ticktick is an id generator for message service.
-pkg_ticktick_homepage = https://github.com/ericliang/ticktick
-pkg_ticktick_fetch = git
-pkg_ticktick_repo = https://github.com/ericliang/ticktick
-pkg_ticktick_commit = master
-
 PACKAGES += tinymq
 pkg_tinymq_name = tinymq
 pkg_tinymq_description = TinyMQ - a diminutive, in-memory message queue
@@ -3969,14 +3323,6 @@ pkg_trane_fetch = git
 pkg_trane_repo = https://github.com/massemanet/trane
 pkg_trane_commit = master
 
-PACKAGES += transit
-pkg_transit_name = transit
-pkg_transit_description = transit format for erlang
-pkg_transit_homepage = https://github.com/isaiah/transit-erlang
-pkg_transit_fetch = git
-pkg_transit_repo = https://github.com/isaiah/transit-erlang
-pkg_transit_commit = master
-
 PACKAGES += trie
 pkg_trie_name = trie
 pkg_trie_description = Erlang Trie Implementation
@@ -4001,30 +3347,6 @@ pkg_tunctl_fetch = git
 pkg_tunctl_repo = https://github.com/msantos/tunctl
 pkg_tunctl_commit = master
 
-PACKAGES += twerl
-pkg_twerl_name = twerl
-pkg_twerl_description = Erlang client for the Twitter Streaming API
-pkg_twerl_homepage = https://github.com/lucaspiller/twerl
-pkg_twerl_fetch = git
-pkg_twerl_repo = https://github.com/lucaspiller/twerl
-pkg_twerl_commit = oauth
-
-PACKAGES += twitter_erlang
-pkg_twitter_erlang_name = twitter_erlang
-pkg_twitter_erlang_description = An Erlang twitter client
-pkg_twitter_erlang_homepage = https://github.com/ngerakines/erlang_twitter
-pkg_twitter_erlang_fetch = git
-pkg_twitter_erlang_repo = https://github.com/ngerakines/erlang_twitter
-pkg_twitter_erlang_commit = master
-
-PACKAGES += ucol_nif
-pkg_ucol_nif_name = ucol_nif
-pkg_ucol_nif_description = ICU based collation Erlang module
-pkg_ucol_nif_homepage = https://github.com/refuge/ucol_nif
-pkg_ucol_nif_fetch = git
-pkg_ucol_nif_repo = https://github.com/refuge/ucol_nif
-pkg_ucol_nif_commit = master
-
 PACKAGES += unicorn
 pkg_unicorn_name = unicorn
 pkg_unicorn_description = Generic configuration server
@@ -4057,14 +3379,6 @@ pkg_ux_fetch = git
 pkg_ux_repo = https://github.com/erlang-unicode/ux
 pkg_ux_commit = master
 
-PACKAGES += vert
-pkg_vert_name = vert
-pkg_vert_description = Erlang binding to libvirt virtualization API
-pkg_vert_homepage = https://github.com/msantos/erlang-libvirt
-pkg_vert_fetch = git
-pkg_vert_repo = https://github.com/msantos/erlang-libvirt
-pkg_vert_commit = master
-
 PACKAGES += verx
 pkg_verx_name = verx
 pkg_verx_description = Erlang implementation of the libvirtd remote protocol
@@ -4073,14 +3387,6 @@ pkg_verx_fetch = git
 pkg_verx_repo = https://github.com/msantos/verx
 pkg_verx_commit = master
 
-PACKAGES += vmq_acl
-pkg_vmq_acl_name = vmq_acl
-pkg_vmq_acl_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_acl_homepage = https://verne.mq/
-pkg_vmq_acl_fetch = git
-pkg_vmq_acl_repo = https://github.com/erlio/vmq_acl
-pkg_vmq_acl_commit = master
-
 PACKAGES += vmq_bridge
 pkg_vmq_bridge_name = vmq_bridge
 pkg_vmq_bridge_description = Component of VerneMQ: A distributed MQTT message broker
@@ -4089,46 +3395,6 @@ pkg_vmq_bridge_fetch = git
 pkg_vmq_bridge_repo = https://github.com/erlio/vmq_bridge
 pkg_vmq_bridge_commit = master
 
-PACKAGES += vmq_graphite
-pkg_vmq_graphite_name = vmq_graphite
-pkg_vmq_graphite_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_graphite_homepage = https://verne.mq/
-pkg_vmq_graphite_fetch = git
-pkg_vmq_graphite_repo = https://github.com/erlio/vmq_graphite
-pkg_vmq_graphite_commit = master
-
-PACKAGES += vmq_passwd
-pkg_vmq_passwd_name = vmq_passwd
-pkg_vmq_passwd_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_passwd_homepage = https://verne.mq/
-pkg_vmq_passwd_fetch = git
-pkg_vmq_passwd_repo = https://github.com/erlio/vmq_passwd
-pkg_vmq_passwd_commit = master
-
-PACKAGES += vmq_server
-pkg_vmq_server_name = vmq_server
-pkg_vmq_server_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_server_homepage = https://verne.mq/
-pkg_vmq_server_fetch = git
-pkg_vmq_server_repo = https://github.com/erlio/vmq_server
-pkg_vmq_server_commit = master
-
-PACKAGES += vmq_snmp
-pkg_vmq_snmp_name = vmq_snmp
-pkg_vmq_snmp_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_snmp_homepage = https://verne.mq/
-pkg_vmq_snmp_fetch = git
-pkg_vmq_snmp_repo = https://github.com/erlio/vmq_snmp
-pkg_vmq_snmp_commit = master
-
-PACKAGES += vmq_systree
-pkg_vmq_systree_name = vmq_systree
-pkg_vmq_systree_description = Component of VerneMQ: A distributed MQTT message broker
-pkg_vmq_systree_homepage = https://verne.mq/
-pkg_vmq_systree_fetch = git
-pkg_vmq_systree_repo = https://github.com/erlio/vmq_systree
-pkg_vmq_systree_commit = master
-
 PACKAGES += vmstats
 pkg_vmstats_name = vmstats
 pkg_vmstats_description = tiny Erlang app that works in conjunction with statsderl in order to generate information on the Erlang VM for graphite logs.
@@ -4167,7 +3433,7 @@ pkg_worker_pool_description = a simple e
 pkg_worker_pool_homepage = https://github.com/inaka/worker_pool
 pkg_worker_pool_fetch = git
 pkg_worker_pool_repo = https://github.com/inaka/worker_pool
-pkg_worker_pool_commit = master
+pkg_worker_pool_commit = main
 
 PACKAGES += wrangler
 pkg_wrangler_name = wrangler
@@ -4225,30 +3491,6 @@ pkg_yaws_fetch = git
 pkg_yaws_repo = https://github.com/klacke/yaws
 pkg_yaws_commit = master
 
-PACKAGES += zab_engine
-pkg_zab_engine_name = zab_engine
-pkg_zab_engine_description = zab propotocol implement by erlang
-pkg_zab_engine_homepage = https://github.com/xinmingyao/zab_engine
-pkg_zab_engine_fetch = git
-pkg_zab_engine_repo = https://github.com/xinmingyao/zab_engine
-pkg_zab_engine_commit = master
-
-PACKAGES += zabbix_sender
-pkg_zabbix_sender_name = zabbix_sender
-pkg_zabbix_sender_description = Zabbix trapper for sending data to Zabbix in pure Erlang
-pkg_zabbix_sender_homepage = https://github.com/stalkermn/zabbix_sender
-pkg_zabbix_sender_fetch = git
-pkg_zabbix_sender_repo = https://github.com/stalkermn/zabbix_sender.git
-pkg_zabbix_sender_commit = master
-
-PACKAGES += zeta
-pkg_zeta_name = zeta
-pkg_zeta_description = HTTP access log parser in Erlang
-pkg_zeta_homepage = https://github.com/s1n4/zeta
-pkg_zeta_fetch = git
-pkg_zeta_repo = https://github.com/s1n4/zeta
-pkg_zeta_commit = master
-
 PACKAGES += zippers
 pkg_zippers_name = zippers
 pkg_zippers_description = A library for functional zipper data structures in Erlang. Read more on zippers
@@ -4265,14 +3507,6 @@ pkg_zlists_fetch = git
 pkg_zlists_repo = https://github.com/vjache/erlang-zlists
 pkg_zlists_commit = master
 
-PACKAGES += zraft_lib
-pkg_zraft_lib_name = zraft_lib
-pkg_zraft_lib_description = Erlang raft consensus protocol implementation
-pkg_zraft_lib_homepage = https://github.com/dreyk/zraft_lib
-pkg_zraft_lib_fetch = git
-pkg_zraft_lib_repo = https://github.com/dreyk/zraft_lib
-pkg_zraft_lib_commit = master
-
 PACKAGES += zucchini
 pkg_zucchini_name = zucchini
 pkg_zucchini_description = An Erlang INI parser
@@ -4331,8 +3565,15 @@ export DEPS_DIR
 REBAR_DEPS_DIR = $(DEPS_DIR)
 export REBAR_DEPS_DIR
 
-REBAR_GIT ?= https://github.com/rebar/rebar
-REBAR_COMMIT ?= 576e12171ab8d69b048b827b92aa65d067deea01
+# When testing Erlang.mk and updating these, make sure
+# to delete test/test_rebar_git before running tests again.
+REBAR3_GIT ?= https://github.com/erlang/rebar3
+REBAR3_COMMIT ?= bde4b54248d16280b2c70a244aca3bb7566e2033 # 3.23.0
+
+CACHE_DEPS ?= 0
+
+CACHE_DIR ?= $(if $(XDG_CACHE_HOME),$(XDG_CACHE_HOME),$(HOME)/.cache)/erlang.mk
+export CACHE_DIR
 
 # External "early" plugins (see core/plugins.mk for regular plugins).
 # They both use the core_dep_plugin macro.
@@ -4516,6 +3757,9 @@ ifneq ($(ALL_DEPS_DIRS),)
 			echo $$dep >> $(ERLANG_MK_TMP)/deps.log; \
 			if [ -z "$(strip $(FULL))" ] $(if $(force_rebuild_dep),&& ! ($(call force_rebuild_dep,$$dep)),) && [ ! -L $$dep ] && [ -f $$dep/ebin/dep_built ]; then \
 				:; \
+			elif [ "$$dep" = "$(DEPS_DIR)/hut" -a "$(HUT_PATCH)" ]; then \
+				$(MAKE) -C $$dep app IS_DEP=1; \
+				if [ ! -L $$dep ] && [ -d $$dep/ebin ]; then touch $$dep/ebin/dep_built; fi; \
 			elif [ -f $$dep/GNUmakefile ] || [ -f $$dep/makefile ] || [ -f $$dep/Makefile ]; then \
 				$(MAKE) -C $$dep IS_DEP=1; \
 				if [ ! -L $$dep ] && [ -d $$dep/ebin ]; then touch $$dep/ebin/dep_built; fi; \
@@ -4611,10 +3855,10 @@ define dep_autopatch_fetch_rebar
 endef
 
 define dep_autopatch_fetch_rebar2
-	if [ ! -d $(ERLANG_MK_TMP)/rebar ]; then \
-		git clone -q -n -- $(REBAR_GIT) $(ERLANG_MK_TMP)/rebar; \
-		cd $(ERLANG_MK_TMP)/rebar; \
-		git checkout -q $(REBAR_COMMIT); \
+	if [ ! -d $(ERLANG_MK_TMP)/rebar3 ]; then \
+		git clone -q -n -- $(REBAR3_GIT) $(ERLANG_MK_TMP)/rebar3; \
+		cd $(ERLANG_MK_TMP)/rebar3; \
+		git checkout -q $(REBAR3_COMMIT); \
 		./bootstrap; \
 		cd -; \
 	fi
@@ -4631,7 +3875,7 @@ endef
 define dep_autopatch_rebar.erl
 	application:load(rebar),
 	application:set_env(rebar, log_level, debug),
-	rmemo:start(),
+	{module, rebar3} = c:l(rebar3),
 	Conf1 = case file:consult("$(call core_native_path,$(DEPS_DIR)/$1/rebar.config)") of
 		{ok, Conf0} -> Conf0;
 		_ -> []
@@ -4665,7 +3909,7 @@ define dep_autopatch_rebar.erl
 		(V) when is_list(V) -> "'\\"" ++ V ++ "\\"'"
 	end,
 	fun() ->
-		Write("ERLC_OPTS = +debug_info\nexport ERLC_OPTS\n"),
+		Write("ERLC_OPTS = +debug_info\n"),
 		case lists:keyfind(erl_opts, 1, Conf) of
 			false -> ok;
 			{_, ErlOpts} ->
@@ -4688,7 +3932,7 @@ define dep_autopatch_rebar.erl
 		end,
 		Write("\n")
 	end(),
-	GetHexVsn = fun(N, NP) ->
+	GetHexVsn2 = fun(N, NP) ->
 		case file:consult("$(call core_native_path,$(DEPS_DIR)/$1/rebar.lock)") of
 			{ok, Lock} ->
 				io:format("~p~n", [Lock]),
@@ -4720,28 +3964,39 @@ define dep_autopatch_rebar.erl
 				false
 		end
 	end,
-	SemVsn = fun
-		("~>" ++ S0) ->
-			S = case S0 of
-				" " ++ S1 -> S1;
-				_ -> S0
-			end,
-			case length([ok || $$. <- S]) of
-				0 -> S ++ ".0.0";
-				1 -> S ++ ".0";
-				_ -> S
-			end;
-		(S) -> S
+	GetHexVsn3Common = fun(N, NP, S0) ->
+		case GetHexVsn2(N, NP) of
+			false ->
+				S2 = case S0 of
+					" " ++ S1 -> S1;
+					_ -> S0
+				end,
+				S = case length([ok || $$. <- S2]) of
+					0 -> S2 ++ ".0.0";
+					1 -> S2 ++ ".0";
+					_ -> S2
+				end,
+				{N, {hex, NP, S}};
+			NameSource ->
+				NameSource
+		end
+	end,
+	GetHexVsn3 = fun
+		(N, NP, "~>" ++ S0) ->
+			GetHexVsn3Common(N, NP, S0);
+		(N, NP, ">=" ++ S0) ->
+			GetHexVsn3Common(N, NP, S0);
+		(N, NP, S) -> {N, {hex, NP, S}}
 	end,
 	fun() ->
 		File = case lists:keyfind(deps, 1, Conf) of
 			false -> [];
 			{_, Deps} ->
 				[begin case case Dep of
-							N when is_atom(N) -> GetHexVsn(N, N);
-							{N, S} when is_atom(N), is_list(S) -> {N, {hex, N, SemVsn(S)}};
-							{N, {pkg, NP}} when is_atom(N) -> GetHexVsn(N, NP);
-							{N, S, {pkg, NP}} -> {N, {hex, NP, S}};
+							N when is_atom(N) -> GetHexVsn2(N, N);
+							{N, S} when is_atom(N), is_list(S) -> GetHexVsn3(N, N, S);
+							{N, {pkg, NP}} when is_atom(N) -> GetHexVsn2(N, NP);
+							{N, S, {pkg, NP}} -> GetHexVsn3(N, NP, S);
 							{N, S} when is_tuple(S) -> {N, S};
 							{N, _, S} -> {N, S};
 							{N, _, S, _} -> {N, S};
@@ -4764,13 +4019,16 @@ define dep_autopatch_rebar.erl
 	fun() ->
 		case lists:keyfind(erl_first_files, 1, Conf) of
 			false -> ok;
-			{_, Files} ->
+			{_, Files0} ->
+				Files = [begin
+					hd(filelib:wildcard("$(call core_native_path,$(DEPS_DIR)/$1/src/)**/" ++ filename:rootname(F) ++ ".*rl"))
+				end || "src/" ++ F <- Files0],
 				Names = [[" ", case lists:reverse(F) of
 					"lre." ++ Elif -> lists:reverse(Elif);
 					"lrx." ++ Elif -> lists:reverse(Elif);
 					"lry." ++ Elif -> lists:reverse(Elif);
 					Elif -> lists:reverse(Elif)
-				end] || "src/" ++ F <- Files],
+				end] || "$(call core_native_path,$(DEPS_DIR)/$1/src/)" ++ F <- Files],
 				Write(io_lib:format("COMPILE_FIRST +=~s\n", [Names]))
 		end
 	end(),
@@ -4797,6 +4055,8 @@ define dep_autopatch_rebar.erl
 						Write("\npre-deps::\n\t" ++ PatchHook(Cmd) ++ "\n");
 					{compile, Cmd} ->
 						Write("\npre-app::\n\tCC=$$\(CC) " ++ PatchHook(Cmd) ++ "\n");
+					{{pc, compile}, Cmd} ->
+						Write("\npre-app::\n\tCC=$$\(CC) " ++ PatchHook(Cmd) ++ "\n");
 					{Regex, compile, Cmd} ->
 						case rebar_utils:is_arch(Regex) of
 							true -> Write("\npre-app::\n\tCC=$$\(CC) " ++ PatchHook(Cmd) ++ "\n");
@@ -4887,9 +4147,11 @@ define dep_autopatch_rebar.erl
 					[[Output, ": ", K, " += ", ShellToMk(V), "\n"] || {K, V} <- lists:reverse(MergeEnv(FilterEnv(Env)))],
 					Output, ": $$\(foreach ext,.c .C .cc .cpp,",
 						"$$\(patsubst %$$\(ext),%.o,$$\(filter %$$\(ext),$$\(wildcard", Input, "))))\n",
-					"\t$$\(CC) -o $$\@ $$\? $$\(LDFLAGS) $$\(ERL_LDFLAGS) $$\(DRV_LDFLAGS) $$\(EXE_LDFLAGS)",
+					"\t$$\(CC) -o $$\@ $$\? $$\(LDFLAGS) $$\(ERL_LDFLAGS) $$\(DRV_LDFLAGS) $$\(LDLIBS) $$\(EXE_LDFLAGS)",
 					case {filename:extension(Output), $(PLATFORM)} of
 					    {[], _} -> "\n";
+					    {".so", darwin} -> " -shared\n";
+					    {".dylib", darwin} -> " -shared\n";
 					    {_, darwin} -> "\n";
 					    _ -> " -shared\n"
 					end])
@@ -4994,9 +4256,39 @@ define dep_autopatch_appsrc.erl
 	halt()
 endef
 
+ifeq ($(CACHE_DEPS),1)
+
+define dep_cache_fetch_git
+	mkdir -p $(CACHE_DIR)/git; \
+	if test -d "$(join $(CACHE_DIR)/git/,$(call dep_name,$1))"; then \
+		cd $(join $(CACHE_DIR)/git/,$(call dep_name,$1)); \
+		if ! git checkout -q $(call dep_commit,$1); then \
+			git remote set-url origin $(call dep_repo,$1) && \
+			git pull --all && \
+			git cat-file -e $(call dep_commit,$1) 2>/dev/null; \
+		fi; \
+	else \
+		git clone -q -n -- $(call dep_repo,$1) $(join $(CACHE_DIR)/git/,$(call dep_name,$1)); \
+	fi; \
+	git clone -q --branch $(call dep_commit,$1) --single-branch -- $(join $(CACHE_DIR)/git/,$(call dep_name,$1)) $2
+endef
+
+define dep_fetch_git
+	$(call dep_cache_fetch_git,$1,$(DEPS_DIR)/$(call dep_name,$1));
+endef
+
+define dep_fetch_git-subfolder
+	mkdir -p $(ERLANG_MK_TMP)/git-subfolder; \
+	$(call dep_cache_fetch_git,$1,$(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1)); \
+	ln -s $(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1)/$(word 4,$(dep_$1)) \
+		$(DEPS_DIR)/$(call dep_name,$1);
+endef
+
+else
+
 define dep_fetch_git
-	git clone -q -n -- $(call dep_repo,$(1)) $(DEPS_DIR)/$(call dep_name,$(1)); \
-	cd $(DEPS_DIR)/$(call dep_name,$(1)) && git checkout -q $(call dep_commit,$(1));
+	git clone -q -n -- $(call dep_repo,$1) $(DEPS_DIR)/$(call dep_name,$1); \
+	cd $(DEPS_DIR)/$(call dep_name,$1) && git checkout -q $(call dep_commit,$1);
 endef
 
 define dep_fetch_git-subfolder
@@ -5005,10 +4297,12 @@ define dep_fetch_git-subfolder
 		$(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1); \
 	cd $(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1) \
 		&& git checkout -q $(call dep_commit,$1); \
-	ln -s $(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1)/$(word 4,$(dep_$(1))) \
+	ln -s $(ERLANG_MK_TMP)/git-subfolder/$(call dep_name,$1)/$(word 4,$(dep_$1)) \
 		$(DEPS_DIR)/$(call dep_name,$1);
 endef
 
+endif
+
 define dep_fetch_git-submodule
 	git submodule update --init -- $(DEPS_DIR)/$1;
 endef
@@ -5030,6 +4324,19 @@ define dep_fetch_ln
 	ln -s $(call dep_repo,$(1)) $(DEPS_DIR)/$(call dep_name,$(1));
 endef
 
+ifeq ($(CACHE_DEPS),1)
+
+# Hex only has a package version. No need to look in the Erlang.mk packages.
+define dep_fetch_hex
+	mkdir -p $(CACHE_DIR)/hex $(DEPS_DIR)/$1; \
+	$(eval hex_tar_name=$(if $(word 3,$(dep_$1)),$(word 3,$(dep_$1)),$1)-$(strip $(word 2,$(dep_$1))).tar) \
+	$(if $(wildcard $(CACHE_DIR)/hex/$(hex_tar_name)),,$(call core_http_get,$(CACHE_DIR)/hex/$(hex_tar_name),\
+		https://repo.hex.pm/tarballs/$(hex_tar_name);)) \
+	tar -xOf $(CACHE_DIR)/hex/$(hex_tar_name) contents.tar.gz | tar -C $(DEPS_DIR)/$1 -xzf -;
+endef
+
+else
+
 # Hex only has a package version. No need to look in the Erlang.mk packages.
 define dep_fetch_hex
 	mkdir -p $(ERLANG_MK_TMP)/hex $(DEPS_DIR)/$1; \
@@ -5038,6 +4345,8 @@ define dep_fetch_hex
 	tar -xOf $(ERLANG_MK_TMP)/hex/$1.tar contents.tar.gz | tar -C $(DEPS_DIR)/$1 -xzf -;
 endef
 
+endif
+
 define dep_fetch_fail
 	echo "Error: Unknown or invalid dependency: $(1)." >&2; \
 	exit 78;
@@ -5076,22 +4385,7 @@ endif
 .PHONY: autopatch-$(call dep_name,$1)
 
 autopatch-$(call dep_name,$1)::
-	$(verbose) if [ "$(1)" = "amqp_client" -a "$(RABBITMQ_CLIENT_PATCH)" ]; then \
-		if [ ! -d $(DEPS_DIR)/rabbitmq-codegen ]; then \
-			echo " PATCH  Downloading rabbitmq-codegen"; \
-			git clone https://github.com/rabbitmq/rabbitmq-codegen.git $(DEPS_DIR)/rabbitmq-codegen; \
-		fi; \
-		if [ ! -d $(DEPS_DIR)/rabbitmq-server ]; then \
-			echo " PATCH  Downloading rabbitmq-server"; \
-			git clone https://github.com/rabbitmq/rabbitmq-server.git $(DEPS_DIR)/rabbitmq-server; \
-		fi; \
-		ln -s $(DEPS_DIR)/amqp_client/deps/rabbit_common-0.0.0 $(DEPS_DIR)/rabbit_common; \
-	elif [ "$(1)" = "rabbit" -a "$(RABBITMQ_SERVER_PATCH)" ]; then \
-		if [ ! -d $(DEPS_DIR)/rabbitmq-codegen ]; then \
-			echo " PATCH  Downloading rabbitmq-codegen"; \
-			git clone https://github.com/rabbitmq/rabbitmq-codegen.git $(DEPS_DIR)/rabbitmq-codegen; \
-		fi \
-	elif [ "$1" = "elixir" -a "$(ELIXIR_PATCH)" ]; then \
+	$(verbose) if [ "$1" = "elixir" -a "$(ELIXIR_PATCH)" ]; then \
 		ln -s lib/elixir/ebin $(DEPS_DIR)/elixir/; \
 	else \
 		$$(call dep_autopatch,$(call dep_name,$1)) \
@@ -5123,6 +4417,16 @@ distclean-deps:
 	$(gen_verbose) rm -rf $(DEPS_DIR)
 endif
 
+ifeq ($(CACHE_DEPS),1)
+cacheclean:: cacheclean-git cacheclean-hex
+
+cacheclean-git:
+	$(gen_verbose) rm -rf $(CACHE_DIR)/git
+
+cacheclean-hex:
+	$(gen_verbose) rm -rf $(CACHE_DIR)/hex
+endif
+
 # Forward-declare variables used in core/deps-tools.mk. This is required
 # in case plugins use them.
 
@@ -5145,7 +4449,7 @@ ERLANG_MK_QUERY_SHELL_DEPS_FILE = $(ERLA
 
 # Configuration.
 
-ERLC_OPTS ?= -Werror +debug_info +warn_export_vars +warn_shadow_vars \
+ERLC_OPTS ?= +debug_info +warn_export_vars +warn_shadow_vars \
 	+warn_obsolete_guard # +bin_opt_info +warn_export_all +warn_missing_spec
 COMPILE_FIRST ?=
 COMPILE_FIRST_PATHS = $(addprefix src/,$(addsuffix .erl,$(COMPILE_FIRST)))
@@ -5205,7 +4509,8 @@ define app_file
 	{id$(comma)$(space)"$(1)"}$(comma))
 	{modules, [$(call comma_list,$(2))]},
 	{registered, []},
-	{applications, [$(call comma_list,kernel stdlib $(OTP_DEPS) $(LOCAL_DEPS) $(foreach dep,$(DEPS),$(call dep_name,$(dep))))]},
+	{applications, [$(call comma_list,kernel stdlib $(OTP_DEPS) $(LOCAL_DEPS) $(OPTIONAL_DEPS) $(foreach dep,$(DEPS),$(call dep_name,$(dep))))]},
+	{optional_applications, [$(call comma_list,$(OPTIONAL_DEPS))]},
 	{env, $(subst \,\\,$(PROJECT_ENV))}$(if $(findstring {,$(PROJECT_APP_EXTRA_KEYS)),$(comma)$(newline)$(tab)$(subst \,\\,$(PROJECT_APP_EXTRA_KEYS)),)
 ]}.
 endef
@@ -5217,7 +4522,8 @@ define app_file
 	{id$(comma)$(space)"$(1)"}$(comma))
 	{modules, [$(call comma_list,$(2))]},
 	{registered, [$(call comma_list,$(PROJECT)_sup $(PROJECT_REGISTERED))]},
-	{applications, [$(call comma_list,kernel stdlib $(OTP_DEPS) $(LOCAL_DEPS) $(foreach dep,$(DEPS),$(call dep_name,$(dep))))]},
+	{applications, [$(call comma_list,kernel stdlib $(OTP_DEPS) $(LOCAL_DEPS) $(OPTIONAL_DEPS) $(foreach dep,$(DEPS),$(call dep_name,$(dep))))]},
+	{optional_applications, [$(call comma_list,$(OPTIONAL_DEPS))]},
 	{mod, {$(PROJECT_MOD), []}},
 	{env, $(subst \,\\,$(PROJECT_ENV))}$(if $(findstring {,$(PROJECT_APP_EXTRA_KEYS)),$(comma)$(newline)$(tab)$(subst \,\\,$(PROJECT_APP_EXTRA_KEYS)),)
 ]}.
@@ -5362,7 +4668,6 @@ define makedep.erl
 	end,
 	MakeDepend = fun
 		(F, Fd, Mod, StartLocation) ->
-			{ok, Filename} = file:pid2name(Fd),
 			case io:parse_erl_form(Fd, undefined, StartLocation) of
 				{ok, AbsData, EndLocation} ->
 					case AbsData of
@@ -5713,8 +5018,8 @@ try
 		})
 	end || F <- [$(shell echo $(addprefix $(comma)\",$(addsuffix \",$1)) | sed 's/^.//')]],
 	halt(0)
-catch C:E ->
-	io:format("Exception ~p:~p~nStacktrace: ~p~n", [C, E, erlang:get_stacktrace()]),
+catch C:E$(if $V,:S) ->
+	io:format("Exception: ~p:~p~n$(if $V,Stacktrace: ~p~n)", [C, E$(if $V,$(comma) S)]),
 	halt(1)
 end.
 endef
@@ -6190,7 +5495,7 @@ endif
 	$(verbose) mkdir config/
 	$(verbose) $(call core_render,bs_sys_config,config/sys.config)
 	$(verbose) $(call core_render,bs_vm_args,config/vm.args)
-	$(verbose) awk '/^include erlang.mk/ && !ins {print "BUILD_DEPS += relx";ins=1};{print}' Makefile > Makefile.bak
+	$(verbose) awk '/^include erlang.mk/ && !ins {print "REL_DEPS += relx";ins=1};{print}' Makefile > Makefile.bak
 	$(verbose) mv Makefile.bak Makefile
 
 new-app:
@@ -6265,17 +5570,24 @@ C_SRC_TYPE ?= shared
 ifeq ($(PLATFORM),msys2)
 	C_SRC_OUTPUT_EXECUTABLE_EXTENSION ?= .exe
 	C_SRC_OUTPUT_SHARED_EXTENSION ?= .dll
+	C_SRC_OUTPUT_STATIC_EXTENSION ?= .lib
 else
 	C_SRC_OUTPUT_EXECUTABLE_EXTENSION ?=
 	C_SRC_OUTPUT_SHARED_EXTENSION ?= .so
+	C_SRC_OUTPUT_STATIC_EXTENSION ?= .a
 endif
 
 ifeq ($(C_SRC_TYPE),shared)
 	C_SRC_OUTPUT_FILE = $(C_SRC_OUTPUT)$(C_SRC_OUTPUT_SHARED_EXTENSION)
+else ifeq ($(C_SRC_TYPE),static)
+	C_SRC_OUTPUT_FILE = $(C_SRC_OUTPUT)$(C_SRC_OUTPUT_STATIC_EXTENSION)
 else
 	C_SRC_OUTPUT_FILE = $(C_SRC_OUTPUT)$(C_SRC_OUTPUT_EXECUTABLE_EXTENSION)
 endif
 
+RANLIB ?= ranlib
+ARFLAGS ?= cr
+
 ifeq ($(PLATFORM),msys2)
 # We hardcode the compiler used on MSYS2. The default CC=cc does
 # not produce working code. The "gcc" MSYS2 package also doesn't.
@@ -6303,6 +5615,11 @@ ifneq ($(PLATFORM),msys2)
 	CXXFLAGS += -fPIC
 endif
 
+ifeq ($(C_SRC_TYPE),static)
+	CFLAGS += -DSTATIC_ERLANG_NIF=1
+	CXXFLAGS += -DSTATIC_ERLANG_NIF=1
+endif
+
 CFLAGS += -I"$(ERTS_INCLUDE_DIR)" -I"$(ERL_INTERFACE_INCLUDE_DIR)"
 CXXFLAGS += -I"$(ERTS_INCLUDE_DIR)" -I"$(ERL_INTERFACE_INCLUDE_DIR)"
 
@@ -6319,6 +5636,12 @@ cpp_verbose = $(cpp_verbose_$(V))
 link_verbose_0 = @echo " LD    " $(@F);
 link_verbose = $(link_verbose_$(V))
 
+ar_verbose_0 = @echo " AR    " $(@F);
+ar_verbose = $(ar_verbose_$(V))
+
+ranlib_verbose_0 = @echo " RANLIB" $(@F);
+ranlib_verbose = $(ranlib_verbose_$(V))
+
 # Targets.
 
 ifeq ($(wildcard $(C_SRC_DIR)),)
@@ -6347,11 +5670,19 @@ app:: $(C_SRC_ENV) $(C_SRC_OUTPUT_FILE)
 
 test-build:: $(C_SRC_ENV) $(C_SRC_OUTPUT_FILE)
 
+ifneq ($(C_SRC_TYPE),static)
 $(C_SRC_OUTPUT_FILE): $(OBJECTS)
 	$(verbose) mkdir -p $(dir $@)
 	$(link_verbose) $(CC) $(OBJECTS) \
 		$(LDFLAGS) $(if $(filter $(C_SRC_TYPE),shared),-shared) $(LDLIBS) \
 		-o $(C_SRC_OUTPUT_FILE)
+else
+$(C_SRC_OUTPUT_FILE): $(OBJECTS)
+	$(verbose) mkdir -p $(dir $@)
+	$(ar_verbose) $(AR) $(ARFLAGS) $(C_SRC_OUTPUT_FILE) $(OBJECTS)
+	$(ranlib_verbose) $(RANLIB) $(C_SRC_OUTPUT_FILE)
+endif
+
 
 $(OBJECTS): $(MAKEFILE_LIST) $(C_SRC_ENV)
 
@@ -6502,24 +5833,14 @@ endif
 .PHONY: ci ci-prepare ci-setup
 
 CI_OTP ?=
-CI_HIPE ?=
-CI_ERLLVM ?=
 
-ifeq ($(CI_VM),native)
-ERLC_OPTS += +native
-TEST_ERLC_OPTS += +native
-else ifeq ($(CI_VM),erllvm)
-ERLC_OPTS += +native +'{hipe, [to_llvm]}'
-TEST_ERLC_OPTS += +native +'{hipe, [to_llvm]}'
-endif
-
-ifeq ($(strip $(CI_OTP) $(CI_HIPE) $(CI_ERLLVM)),)
+ifeq ($(strip $(CI_OTP)),)
 ci::
 else
 
-ci:: $(addprefix ci-,$(CI_OTP) $(addsuffix -native,$(CI_HIPE)) $(addsuffix -erllvm,$(CI_ERLLVM)))
+ci:: $(addprefix ci-,$(CI_OTP))
 
-ci-prepare: $(addprefix $(KERL_INSTALL_DIR)/,$(CI_OTP) $(addsuffix -native,$(CI_HIPE)))
+ci-prepare: $(addprefix ci-prepare-,$(CI_OTP))
 
 ci-setup::
 	$(verbose) :
@@ -6531,7 +5852,10 @@ ci_verbose_0 = @echo " CI    " $(1);
 ci_verbose = $(ci_verbose_$(V))
 
 define ci_target
-ci-$1: $(KERL_INSTALL_DIR)/$2
+ci-prepare-$1: $(KERL_INSTALL_DIR)/$2
+	$(verbose) :
+
+ci-$1: ci-prepare-$1
 	$(verbose) $(MAKE) --no-print-directory clean
 	$(ci_verbose) \
 		PATH="$(KERL_INSTALL_DIR)/$2/bin:$(PATH)" \
@@ -6543,11 +5867,8 @@ ci-$1: $(KERL_INSTALL_DIR)/$2
 endef
 
 $(foreach otp,$(CI_OTP),$(eval $(call ci_target,$(otp),$(otp),otp)))
-$(foreach otp,$(CI_HIPE),$(eval $(call ci_target,$(otp)-native,$(otp)-native,native)))
-$(foreach otp,$(CI_ERLLVM),$(eval $(call ci_target,$(otp)-erllvm,$(otp)-native,erllvm)))
 
 $(foreach otp,$(filter-out $(ERLANG_OTP),$(CI_OTP)),$(eval $(call kerl_otp_target,$(otp))))
-$(foreach otp,$(filter-out $(ERLANG_HIPE),$(sort $(CI_HIPE) $(CI_ERLLLVM))),$(eval $(call kerl_hipe_target,$(otp))))
 
 help::
 	$(verbose) printf "%s\n" "" \
@@ -6707,9 +6028,9 @@ endif
 endif
 
 define ct_suite_target
-ct-$(1): test-build
-	$(verbose) mkdir -p $(CT_LOGS_DIR)
-	$(gen_verbose_esc) $(CT_RUN) -sname ct_$(PROJECT) -suite $(addsuffix _SUITE,$(1)) $(CT_EXTRA) $(CT_OPTS)
+ct-$1: test-build
+	$$(verbose) mkdir -p $$(CT_LOGS_DIR)
+	$$(gen_verbose_esc) $$(CT_RUN) -sname ct_$$(PROJECT) -suite $$(addsuffix _SUITE,$1) $$(CT_EXTRA) $$(CT_OPTS)
 endef
 
 $(foreach test,$(CT_SUITES),$(eval $(call ct_suite_target,$(test))))
@@ -6788,7 +6109,7 @@ dialyze: $(if $(filter --src,$(DIALYZER_
 else
 dialyze: $(DIALYZER_PLT)
 endif
-	$(verbose) dialyzer --no_native `$(ERL) \
+	$(verbose) dialyzer `$(ERL) \
 		-eval "$(subst $(newline),,$(call escape_dquotes,$(call filter_opts.erl)))" \
 		-extra $(ERLC_OPTS)` $(DIALYZER_DIRS) $(DIALYZER_OPTS) $(if $(wildcard ebin/),-pa ebin/)
 
@@ -6805,7 +6126,11 @@ EDOC_OUTPUT ?= doc
 
 define edoc.erl
 	SrcPaths = lists:foldl(fun(P, Acc) ->
-		filelib:wildcard(atom_to_list(P) ++ "/{src,c_src}") ++ Acc
+		filelib:wildcard(atom_to_list(P) ++ "/{src,c_src}")
+		++ lists:filter(fun(D) ->
+			filelib:is_dir(D)
+		end, filelib:wildcard(atom_to_list(P) ++ "/{src,c_src}/**"))
+		++ Acc
 	end, [], [$(call comma_list,$(patsubst %,'%',$(call core_native_path,$(EDOC_SRC_DIRS))))]),
 	DefaultOpts = [{dir, "$(EDOC_OUTPUT)"}, {source_path, SrcPaths}, {subpackages, false}],
 	edoc:application($(1), ".", [$(2)] ++ DefaultOpts),
@@ -6922,11 +6247,11 @@ help::
 
 escript-zip:: FULL=1
 escript-zip:: deps app
-	$(verbose) mkdir -p $(dir $(ESCRIPT_ZIP))
-	$(verbose) rm -f $(ESCRIPT_ZIP_FILE)
-	$(gen_verbose) cd .. && $(ESCRIPT_ZIP) $(ESCRIPT_ZIP_FILE) $(PROJECT)/ebin/*
+	$(verbose) mkdir -p $(dir $(abspath $(ESCRIPT_ZIP_FILE)))
+	$(verbose) rm -f $(abspath $(ESCRIPT_ZIP_FILE))
+	$(gen_verbose) cd .. && $(ESCRIPT_ZIP) $(abspath $(ESCRIPT_ZIP_FILE)) $(PROJECT)/ebin/*
 ifneq ($(DEPS),)
-	$(verbose) cd $(DEPS_DIR) && $(ESCRIPT_ZIP) $(ESCRIPT_ZIP_FILE) \
+	$(verbose) cd $(DEPS_DIR) && $(ESCRIPT_ZIP) $(abspath $(ESCRIPT_ZIP_FILE)) \
 		$(subst $(DEPS_DIR)/,,$(addsuffix /*,$(wildcard \
 			$(addsuffix /ebin,$(shell cat $(ERLANG_MK_TMP)/deps.log)))))
 endif
@@ -6936,11 +6261,11 @@ escript:: escript-zip
 		"#!$(ESCRIPT_SHEBANG)" \
 		"%% $(ESCRIPT_COMMENT)" \
 		"%%! $(ESCRIPT_EMU_ARGS)" > $(ESCRIPT_FILE)
-	$(verbose) cat $(ESCRIPT_ZIP_FILE) >> $(ESCRIPT_FILE)
+	$(verbose) cat $(abspath $(ESCRIPT_ZIP_FILE)) >> $(ESCRIPT_FILE)
 	$(verbose) chmod +x $(ESCRIPT_FILE)
 
 distclean-escript:
-	$(gen_verbose) rm -f $(ESCRIPT_FILE)
+	$(gen_verbose) rm -f $(ESCRIPT_FILE) $(abspath $(ESCRIPT_ZIP_FILE))
 
 # Copyright (c) 2015-2016, Loïc Hoguin <essen@ninenines.eu>
 # Copyright (c) 2014, Enrique Fernandez <enrique.fernandez@erlang-solutions.com>
@@ -6952,6 +6277,7 @@ distclean-escript:
 
 EUNIT_OPTS ?=
 EUNIT_ERL_OPTS ?=
+EUNIT_TEST_SPEC ?= $1
 
 # Core targets.
 
@@ -6967,7 +6293,7 @@ help::
 define eunit.erl
 	$(call cover.erl)
 	CoverSetup(),
-	case eunit:test($1, [$(EUNIT_OPTS)]) of
+	case eunit:test($(call EUNIT_TEST_SPEC,$1), [$(EUNIT_OPTS)]) of
 		ok -> ok;
 		error -> halt(2)
 	end,
@@ -7381,8 +6707,8 @@ define proper_check.erl
 	end of
 		true -> halt(0);
 		_ -> halt(1)
-	catch error:undef ->
-		io:format("Undefined property or module?~n~p~n", [erlang:get_stacktrace()]),
+	catch error:undef$(if $V,:Stacktrace) ->
+		io:format("Undefined property or module?~n$(if $V,~p~n)", [$(if $V,Stacktrace)]),
 		halt(0)
 	end.
 endef
@@ -7447,10 +6773,13 @@ else
 define compile_proto.erl
 	[begin
 		gpb_compile:file(F, [
+			$(foreach i,$(sort $(dir $(PROTO_FILES))),{i$(comma) "$i"}$(comma))
 			{include_as_lib, true},
 			{module_name_suffix, "_pb"},
 			{o_hrl, "./include"},
-			{o_erl, "./src"}])
+			{o_erl, "./src"},
+			{use_packages, true}
+		])
 	end || F <- string:tokens("$1", " ")],
 	halt().
 endef
@@ -7473,6 +6802,7 @@ ifeq ($(filter relx,$(BUILD_DEPS) $(DEPS
 # Configuration.
 
 RELX_CONFIG ?= $(CURDIR)/relx.config
+RELX_CONFIG_SCRIPT ?= $(CURDIR)/relx.config.script
 
 RELX_OUTPUT_DIR ?= _rel
 RELX_REL_EXT ?=
@@ -7485,7 +6815,7 @@ endif
 # Core targets.
 
 ifeq ($(IS_DEP),)
-ifneq ($(wildcard $(RELX_CONFIG)),)
+ifneq ($(wildcard $(RELX_CONFIG))$(wildcard $(RELX_CONFIG_SCRIPT)),)
 rel:: relx-rel
 
 relup:: relx-relup
@@ -7496,39 +6826,65 @@ distclean:: distclean-relx-rel
 
 # Plugin-specific targets.
 
+define relx_get_config.erl
+	(fun() ->
+		Config0 =
+			case file:consult("$(call core_native_path,$(RELX_CONFIG))") of
+				{ok, Terms} ->
+					Terms;
+				{error, _} ->
+					[]
+			end,
+		case filelib:is_file("$(call core_native_path,$(RELX_CONFIG_SCRIPT))") of
+			true ->
+				Bindings = erl_eval:add_binding('CONFIG', Config0, erl_eval:new_bindings()),
+				{ok, Config1} = file:script("$(call core_native_path,$(RELX_CONFIG_SCRIPT))", Bindings),
+				Config1;
+			false ->
+				Config0
+		end
+	end)()
+endef
+
 define relx_release.erl
-	{ok, Config} = file:consult("$(call core_native_path,$(RELX_CONFIG))"),
+	Config = $(call relx_get_config.erl),
 	{release, {Name, Vsn0}, _} = lists:keyfind(release, 1, Config),
 	Vsn = case Vsn0 of
 		{cmd, Cmd} -> os:cmd(Cmd);
 		semver -> "";
 		{semver, _} -> "";
+		{git, short} -> string:trim(os:cmd("git rev-parse --short HEAD"), both, "\n");
+		{git, long} -> string:trim(os:cmd("git rev-parse HEAD"), both, "\n");
 		VsnStr -> Vsn0
 	end,
-	{ok, _} = relx:build_release(#{name => Name, vsn => Vsn}, Config),
+	{ok, _} = relx:build_release(#{name => Name, vsn => Vsn}, Config ++ [{output_dir, "$(RELX_OUTPUT_DIR)"}]),
 	halt(0).
 endef
 
 define relx_tar.erl
-	{ok, Config} = file:consult("$(call core_native_path,$(RELX_CONFIG))"),
+	Config = $(call relx_get_config.erl),
 	{release, {Name, Vsn0}, _} = lists:keyfind(release, 1, Config),
 	Vsn = case Vsn0 of
 		{cmd, Cmd} -> os:cmd(Cmd);
 		semver -> "";
 		{semver, _} -> "";
+		{git, short} -> string:trim(os:cmd("git rev-parse --short HEAD"), both, "\n");
+		{git, long} -> string:trim(os:cmd("git rev-parse HEAD"), both, "\n");
 		VsnStr -> Vsn0
 	end,
-	{ok, _} = relx:build_tar(#{name => Name, vsn => Vsn}, Config),
+	{ok, _} = relx:build_tar(#{name => Name, vsn => Vsn}, Config ++ [{output_dir, "$(RELX_OUTPUT_DIR)"}]),
 	halt(0).
 endef
 
 define relx_relup.erl
-	{ok, Config} = file:consult("$(call core_native_path,$(RELX_CONFIG))"),
+	Config = $(call relx_get_config.erl),
 	{release, {Name, Vsn0}, _} = lists:keyfind(release, 1, Config),
 	Vsn = case Vsn0 of
 		{cmd, Cmd} -> os:cmd(Cmd);
 		semver -> "";
 		{semver, _} -> "";
+		{git, short} -> string:trim(os:cmd("git rev-parse --short HEAD"), both, "\n");
+		{git, long} -> string:trim(os:cmd("git rev-parse HEAD"), both, "\n");
 		VsnStr -> Vsn0
 	end,
 	{ok, _} = relx:build_relup(Name, Vsn, undefined, Config ++ [{output_dir, "$(RELX_OUTPUT_DIR)"}]),
@@ -7559,17 +6915,19 @@ relx-post-rel::
 
 # Run target.
 
-ifeq ($(wildcard $(RELX_CONFIG)),)
+ifeq ($(wildcard $(RELX_CONFIG))$(wildcard $(RELX_CONFIG_SCRIPT)),)
 run::
 else
 
 define get_relx_release.erl
-	{ok, Config} = file:consult("$(call core_native_path,$(RELX_CONFIG))"),
+	Config = $(call relx_get_config.erl),
 	{release, {Name, Vsn0}, _} = lists:keyfind(release, 1, Config),
 	Vsn = case Vsn0 of
 		{cmd, Cmd} -> os:cmd(Cmd);
 		semver -> "";
 		{semver, _} -> "";
+		{git, short} -> string:trim(os:cmd("git rev-parse --short HEAD"), both, "\n");
+		{git, long} -> string:trim(os:cmd("git rev-parse HEAD"), both, "\n");
 		VsnStr -> Vsn0
 	end,
 	Extended = case lists:keyfind(extended_start_script, 1, Config) of
@@ -7596,7 +6954,7 @@ ifdef RELOAD
 rel::
 	$(verbose) $(RELX_OUTPUT_DIR)/$(RELX_REL_NAME)/bin/$(RELX_REL_NAME)$(RELX_REL_EXT) ping
 	$(verbose) $(RELX_OUTPUT_DIR)/$(RELX_REL_NAME)/bin/$(RELX_REL_NAME)$(RELX_REL_EXT) \
-		eval "io:format(\"~p~n\", [c:lm()])"
+		eval "io:format(\"~p~n\", [c:lm()])."
 endif
 
 help::
@@ -7754,8 +7112,8 @@ define triq_check.erl
 	end of
 		true -> halt(0);
 		_ -> halt(1)
-	catch error:undef ->
-		io:format("Undefined property or module?~n~p~n", [erlang:get_stacktrace()]),
+	catch error:undef$(if $V,:Stacktrace) ->
+		io:format("Undefined property or module?~n$(if $V,~p~n)", [$(if $V,Stacktrace)]),
 		halt(0)
 	end.
 endef
@@ -8006,6 +7364,7 @@ COVER_DATA_DIR ?= $(COVER_REPORT_DIR)
 ifdef COVER
 COVER_APPS ?= $(notdir $(ALL_APPS_DIRS))
 COVER_DEPS ?=
+COVER_EXCLUDE_MODS ?=
 endif
 
 # Code coverage for Common Test.
@@ -8021,7 +7380,8 @@ $(TEST_DIR)/ct.cover.spec: cover-data-di
 		"{incl_dirs, '$(PROJECT)', [\"$(call core_native_path,$(CURDIR)/ebin)\" \
 			$(foreach a,$(COVER_APPS),$(comma) \"$(call core_native_path,$(APPS_DIR)/$a/ebin)\") \
 			$(foreach d,$(COVER_DEPS),$(comma) \"$(call core_native_path,$(DEPS_DIR)/$d/ebin)\")]}." \
-		'{export,"$(call core_native_path,$(abspath $(COVER_DATA_DIR))/ct.coverdata)"}.' > $@
+		'{export,"$(call core_native_path,$(abspath $(COVER_DATA_DIR))/ct.coverdata)"}.' \
+		"{excl_mods, '$(PROJECT)', [$(call comma_list,$(COVER_EXCLUDE_MODS))]}." > $@
 
 CT_RUN += -cover $(TEST_DIR)/ct.cover.spec
 endif
@@ -8036,14 +7396,18 @@ define cover.erl
 		Dirs = ["$(call core_native_path,$(CURDIR)/ebin)"
 			$(foreach a,$(COVER_APPS),$(comma) "$(call core_native_path,$(APPS_DIR)/$a/ebin)")
 			$(foreach d,$(COVER_DEPS),$(comma) "$(call core_native_path,$(DEPS_DIR)/$d/ebin)")],
-		[begin
-			case filelib:is_dir(Dir) of
-				false -> false;
-				true ->
-					case cover:compile_beam_directory(Dir) of
-						{error, _} -> halt(1);
-						_ -> true
-					end
+		Excludes = [$(call comma_list,$(foreach e,$(COVER_EXCLUDE_MODS),"$e"))],
+		[case file:list_dir(Dir) of
+			{error, enotdir} -> false;
+			{error, _} ->	halt(2);
+			{ok, Files} ->
+			BeamFiles =  [filename:join(Dir, File) ||
+				File <- Files,
+				not lists:member(filename:basename(File, ".beam"), Excludes),
+				filename:extension(File) =:= ".beam"],
+			case cover:compile_beam(BeamFiles) of
+				{error, _} -> halt(1);
+				_ -> true
 			end
 		end || Dir <- Dirs]
 	end,
