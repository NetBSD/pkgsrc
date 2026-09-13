$NetBSD: patch-go.mod,v 1.1 2026/09/13 14:17:54 bsiegert Exp $

- Upgrade the go-limiter package
- Upgrade more dependencies to support newer Go versions
--- go.mod.orig	2021-08-24 20:52:56.000000000 +0000
+++ go.mod
@@ -1,6 +1,6 @@
 module github.com/hashicorp/vault
 
-go 1.15
+go 1.25
 
 replace github.com/hashicorp/vault/api => ./api
 
@@ -16,7 +16,6 @@ require (
 	github.com/NYTimes/gziphandler v1.1.1
 	github.com/SAP/go-hdb v0.14.1
 	github.com/Sectorbob/mlab-ns2 v0.0.0-20171030222938-d3aa0c295a8a
-	github.com/StackExchange/wmi v0.0.0-20190523213315-cbe66965904d // indirect
 	github.com/aliyun/alibaba-cloud-sdk-go v0.0.0-20190620160927-9418d7b0cd0f
 	github.com/aliyun/aliyun-oss-go-sdk v0.0.0-20190307165228-86c17b95fcd5
 	github.com/apple/foundationdb/bindings/go v0.0.0-20190411004307-cd5c9d91fad2
@@ -25,7 +24,6 @@ require (
 	github.com/armon/go-radix v1.0.0
 	github.com/asaskevich/govalidator v0.0.0-20180720115003-f9ffefc3facf
 	github.com/aws/aws-sdk-go v1.34.28
-	github.com/bitly/go-hostpool v0.1.0 // indirect
 	github.com/cenkalti/backoff/v3 v3.0.0
 	github.com/chrismalek/oktasdk-go v0.0.0-20181212195951-3430665dfaa0
 	github.com/client9/misspell v0.3.4
@@ -34,7 +32,6 @@ require (
 	github.com/denisenkom/go-mssqldb v0.0.0-20200428022330-06a60b6afbbc
 	github.com/docker/docker v17.12.0-ce-rc1.0.20200309214505-aa6a9891b09c+incompatible
 	github.com/docker/go-connections v0.4.0
-	github.com/dsnet/compress v0.0.1 // indirect
 	github.com/duosecurity/duo_api_golang v0.0.0-20190308151101-6c680f768e74
 	github.com/elazarl/go-bindata-assetfs v1.0.1-0.20200509193318-234c15e7648f
 	github.com/fatih/color v1.9.0
@@ -43,7 +40,6 @@ require (
 	github.com/ghodss/yaml v1.0.1-0.20190212211648-25d852aebe32
 	github.com/go-errors/errors v1.0.1
 	github.com/go-ldap/ldap/v3 v3.1.10
-	github.com/go-ole/go-ole v1.2.4 // indirect
 	github.com/go-sql-driver/mysql v1.5.0
 	github.com/go-test/deep v1.0.7
 	github.com/gocql/gocql v0.0.0-20210401103645-80ab1e13e309
@@ -118,14 +114,12 @@ require (
 	github.com/mongodb/go-client-mongodb-atlas v0.1.2
 	github.com/natefinch/atomic v0.0.0-20150920032501-a62ce929ffcc
 	github.com/ncw/swift v1.0.47
-	github.com/nwaples/rardecode v1.1.0 // indirect
 	github.com/oklog/run v1.0.0
 	github.com/okta/okta-sdk-golang/v2 v2.0.0
 	github.com/oracle/oci-go-sdk v12.5.0+incompatible
 	github.com/ory/dockertest v3.3.5+incompatible
 	github.com/ory/dockertest/v3 v3.6.2
 	github.com/patrickmn/go-cache v2.1.0+incompatible
-	github.com/petermattis/goid v0.0.0-20180202154549-b0b1615b78e5 // indirect
 	github.com/pkg/errors v0.9.1
 	github.com/posener/complete v1.2.1
 	github.com/pquerna/otp v1.2.1-0.20191009055518-468c2dd2b58d
@@ -136,13 +130,9 @@ require (
 	github.com/ryanuber/go-glob v1.0.0
 	github.com/samuel/go-zookeeper v0.0.0-20190923202752-2cc03de413da
 	github.com/sasha-s/go-deadlock v0.2.0
-	github.com/sethvargo/go-limiter v0.3.0
+	github.com/sethvargo/go-limiter v1.2.0
 	github.com/shirou/gopsutil v2.20.9+incompatible
 	github.com/stretchr/testify v1.6.1
-	github.com/tidwall/pretty v1.0.1 // indirect
-	github.com/ulikunitz/xz v0.5.7 // indirect
-	github.com/xdg/stringprep v1.0.0 // indirect
-	github.com/xi2/xz v0.0.0-20171230120015-48954b6210f8 // indirect
 	go.etcd.io/bbolt v1.3.5
 	go.etcd.io/etcd v0.5.0-alpha.5.0.20200425165423-262c93980547
 	go.mongodb.org/mongo-driver v1.4.2
@@ -159,3 +149,165 @@ require (
 	gopkg.in/square/go-jose.v2 v2.5.1
 	layeh.com/radius v0.0.0-20190322222518-890bc1058917
 )
+
+require (
+	code.cloudfoundry.org/gofileutils v0.0.0-20170111115228-4d0c80011a0f // indirect
+	github.com/Azure/azure-pipeline-go v0.2.3 // indirect
+	github.com/Azure/azure-sdk-for-go v44.0.0+incompatible // indirect
+	github.com/Azure/go-ansiterm v0.0.0-20170929234023-d6e3b3328b78 // indirect
+	github.com/Azure/go-autorest v14.2.0+incompatible // indirect
+	github.com/Azure/go-autorest/autorest/azure/auth v0.5.0 // indirect
+	github.com/Azure/go-autorest/autorest/azure/cli v0.4.0 // indirect
+	github.com/Azure/go-autorest/autorest/date v0.3.0 // indirect
+	github.com/Azure/go-autorest/autorest/to v0.4.0 // indirect
+	github.com/Azure/go-autorest/autorest/validation v0.3.0 // indirect
+	github.com/Azure/go-autorest/logger v0.2.0 // indirect
+	github.com/Azure/go-autorest/tracing v0.6.0 // indirect
+	github.com/BurntSushi/toml v0.3.1 // indirect
+	github.com/DataDog/datadog-go v3.2.0+incompatible // indirect
+	github.com/Jeffail/gabs v1.1.1 // indirect
+	github.com/Masterminds/semver v1.4.2 // indirect
+	github.com/Microsoft/go-winio v0.4.15-0.20190919025122-fc70bd9a86b5 // indirect
+	github.com/Microsoft/hcsshim v0.8.9 // indirect
+	github.com/Nvveen/Gotty v0.0.0-20120604004816-cd527374f1e5 // indirect
+	github.com/StackExchange/wmi v0.0.0-20190523213315-cbe66965904d // indirect
+	github.com/beorn7/perks v1.0.1 // indirect
+	github.com/bgentry/speakeasy v0.1.0 // indirect
+	github.com/bitly/go-hostpool v0.1.0 // indirect
+	github.com/boombuler/barcode v1.0.1-0.20190219062509-6c824513bacc // indirect
+	github.com/briankassouf/jose v0.9.2-0.20180619214549-d2569464773f // indirect
+	github.com/cenkalti/backoff v2.2.1+incompatible // indirect
+	github.com/centrify/cloud-golang-sdk v0.0.0-20190214225812-119110094d0f // indirect
+	github.com/cespare/xxhash/v2 v2.1.1 // indirect
+	github.com/circonus-labs/circonus-gometrics v2.3.1+incompatible // indirect
+	github.com/circonus-labs/circonusllhist v0.1.3 // indirect
+	github.com/cloudfoundry-community/go-cfclient v0.0.0-20190201205600-f136f9222381 // indirect
+	github.com/containerd/containerd v1.3.4 // indirect
+	github.com/containerd/continuity v0.0.0-20200710164510-efbc4488d8fe // indirect
+	github.com/coreos/go-oidc v2.1.0+incompatible // indirect
+	github.com/coreos/go-systemd/v22 v22.0.0 // indirect
+	github.com/couchbase/gocb/v2 v2.1.4 // indirect
+	github.com/couchbase/gocbcore/v9 v9.0.4 // indirect
+	github.com/davecgh/go-spew v1.1.1 // indirect
+	github.com/denverdino/aliyungo v0.0.0-20170926055100-d3308649c661 // indirect
+	github.com/digitalocean/godo v1.7.5 // indirect
+	github.com/dimchansky/utfbom v1.1.0 // indirect
+	github.com/docker/distribution v2.7.1+incompatible // indirect
+	github.com/docker/go-units v0.4.0 // indirect
+	github.com/dsnet/compress v0.0.1 // indirect
+	github.com/form3tech-oss/jwt-go v3.2.2+incompatible // indirect
+	github.com/gammazero/deque v0.0.0-20190130191400-2afb3858e9c7 // indirect
+	github.com/gammazero/workerpool v0.0.0-20190406235159-88d534f22b56 // indirect
+	github.com/go-asn1-ber/asn1-ber v1.3.1 // indirect
+	github.com/go-ole/go-ole v1.2.4 // indirect
+	github.com/go-stack/stack v1.8.0 // indirect
+	github.com/go-yaml/yaml v2.1.0+incompatible // indirect
+	github.com/gogo/protobuf v1.3.1 // indirect
+	github.com/golang-sql/civil v0.0.0-20190719163853-cb61b32ac6fe // indirect
+	github.com/golang/groupcache v0.0.0-20200121045136-8c9f03a8e57e // indirect
+	github.com/golang/snappy v0.0.1 // indirect
+	github.com/google/go-cmp v0.5.2 // indirect
+	github.com/google/go-querystring v1.0.0 // indirect
+	github.com/google/gofuzz v1.1.0 // indirect
+	github.com/google/uuid v1.1.1 // indirect
+	github.com/googleapis/gax-go/v2 v2.0.5 // indirect
+	github.com/googleapis/gnostic v0.2.0 // indirect
+	github.com/gophercloud/gophercloud v0.1.0 // indirect
+	github.com/gorhill/cronexpr v0.0.0-20180427100037-88b0669f7d75 // indirect
+	github.com/gorilla/websocket v1.4.1 // indirect
+	github.com/hailocab/go-hostpool v0.0.0-20160125115350-e80d13ce29ed // indirect
+	github.com/hashicorp/go-immutable-radix v1.1.0 // indirect
+	github.com/hashicorp/go-kms-wrapping/entropy v0.1.0 // indirect
+	github.com/hashicorp/go-plugin v1.0.1 // indirect
+	github.com/hashicorp/go-version v1.2.1 // indirect
+	github.com/hashicorp/logutils v1.0.0 // indirect
+	github.com/hashicorp/mdns v1.0.1 // indirect
+	github.com/hashicorp/serf v0.8.3 // indirect
+	github.com/hashicorp/vic v1.5.1-0.20190403131502-bbfe86ec9443 // indirect
+	github.com/hashicorp/yamux v0.0.0-20181012175058-2f1d1f20f75d // indirect
+	github.com/imdario/mergo v0.3.6 // indirect
+	github.com/jackc/pgx v3.3.0+incompatible // indirect
+	github.com/jcmturner/aescts v1.0.1 // indirect
+	github.com/jcmturner/dnsutils v1.0.1 // indirect
+	github.com/jcmturner/gofork v1.0.0 // indirect
+	github.com/jcmturner/goidentity/v6 v6.0.1 // indirect
+	github.com/jcmturner/rpc/v2 v2.0.2 // indirect
+	github.com/jeffchao/backoff v0.0.0-20140404060208-9d7fd7aa17f2 // indirect
+	github.com/jmespath/go-jmespath v0.4.0 // indirect
+	github.com/json-iterator/go v1.1.10 // indirect
+	github.com/jstemmer/go-junit-report v0.9.1 // indirect
+	github.com/kelseyhightower/envconfig v1.4.0 // indirect
+	github.com/klauspost/compress v1.9.5 // indirect
+	github.com/konsorten/go-windows-terminal-sequences v1.0.3 // indirect
+	github.com/linode/linodego v0.7.1 // indirect
+	github.com/mattn/go-ieproxy v0.0.1 // indirect
+	github.com/mattn/go-isatty v0.0.12 // indirect
+	github.com/mattn/go-shellwords v1.0.5 // indirect
+	github.com/matttproud/golang_protobuf_extensions v1.0.1 // indirect
+	github.com/miekg/dns v1.1.15 // indirect
+	github.com/mitchellh/hashstructure v1.0.0 // indirect
+	github.com/mitchellh/iochan v1.0.0 // indirect
+	github.com/mitchellh/pointerstructure v1.0.0 // indirect
+	github.com/moby/term v0.0.0-20200915141129-7f0af18e79f2 // indirect
+	github.com/modern-go/concurrent v0.0.0-20180306012644-bacd9c7ef1dd // indirect
+	github.com/modern-go/reflect2 v1.0.1 // indirect
+	github.com/mwielbut/pointy v1.1.0 // indirect
+	github.com/nicolai86/scaleway-sdk v1.10.2-0.20180628010248-798f60e20bb2 // indirect
+	github.com/nwaples/rardecode v1.1.0 // indirect
+	github.com/okta/okta-sdk-golang v1.1.0 // indirect
+	github.com/opencontainers/go-digest v1.0.0 // indirect
+	github.com/opencontainers/image-spec v1.0.1 // indirect
+	github.com/opencontainers/runc v1.0.0-rc9 // indirect
+	github.com/openlyinc/pointy v1.1.2 // indirect
+	github.com/packethost/packngo v0.1.1-0.20180711074735-b9cb5096f54c // indirect
+	github.com/petermattis/goid v0.0.0-20180202154549-b0b1615b78e5 // indirect
+	github.com/pierrec/lz4 v2.5.2+incompatible // indirect
+	github.com/pmezard/go-difflib v1.0.0 // indirect
+	github.com/pquerna/cachecontrol v0.0.0-20180517163645-1555304b9b35 // indirect
+	github.com/prometheus/client_model v0.2.0 // indirect
+	github.com/prometheus/procfs v0.1.3 // indirect
+	github.com/renier/xmlrpc v0.0.0-20170708154548-ce4a1a486c03 // indirect
+	github.com/sirupsen/logrus v1.6.0 // indirect
+	github.com/softlayer/softlayer-go v0.0.0-20180806151055-260589d94c7d // indirect
+	github.com/spf13/pflag v1.0.5 // indirect
+	github.com/stretchr/objx v0.2.0 // indirect
+	github.com/tencentcloud/tencentcloud-sdk-go v3.0.171+incompatible // indirect
+	github.com/tidwall/pretty v1.0.1 // indirect
+	github.com/tv42/httpunix v0.0.0-20150427012821-b75d8614f926 // indirect
+	github.com/ulikunitz/xz v0.5.7 // indirect
+	github.com/vmware/govmomi v0.18.0 // indirect
+	github.com/xdg/scram v0.0.0-20180814205039-7eeb5667e42c // indirect
+	github.com/xdg/stringprep v1.0.0 // indirect
+	github.com/xi2/xz v0.0.0-20171230120015-48954b6210f8 // indirect
+	go.mongodb.org/atlas v0.7.1 // indirect
+	go.opencensus.io v0.22.3 // indirect
+	go.uber.org/multierr v1.5.0 // indirect
+	go.uber.org/zap v1.14.1 // indirect
+	golang.org/x/lint v0.0.0-20200302205851-738671d3881b // indirect
+	golang.org/x/mod v0.2.0 // indirect
+	golang.org/x/sync v0.0.0-20200317015054-43a5402ce75a // indirect
+	golang.org/x/sys v0.0.0-20200831180312-196b9ba8737a // indirect
+	golang.org/x/text v0.3.3 // indirect
+	golang.org/x/time v0.0.0-20200416051211-89c76fbcd5d1 // indirect
+	golang.org/x/xerrors v0.0.0-20191204190536-9bdfabe68543 // indirect
+	google.golang.org/appengine v1.6.5 // indirect
+	google.golang.org/genproto v0.0.0-20200526211855-cb27e3aa2013 // indirect
+	gopkg.in/inf.v0 v0.9.1 // indirect
+	gopkg.in/ini.v1 v1.42.0 // indirect
+	gopkg.in/jcmturner/goidentity.v3 v3.0.0 // indirect
+	gopkg.in/resty.v1 v1.12.0 // indirect
+	gopkg.in/yaml.v2 v2.3.0 // indirect
+	gopkg.in/yaml.v3 v3.0.0-20200313102051-9f266ea9e77c // indirect
+	honnef.co/go/tools v0.0.1-2020.1.3 // indirect
+	k8s.io/api v0.18.2 // indirect
+	k8s.io/apimachinery v0.18.2 // indirect
+	k8s.io/client-go v0.18.2 // indirect
+	k8s.io/klog v1.0.0 // indirect
+	k8s.io/utils v0.0.0-20200324210504-a9aa75ae1b89 // indirect
+	sigs.k8s.io/structured-merge-diff/v3 v3.0.0 // indirect
+	sigs.k8s.io/yaml v1.2.0 // indirect
+)
+
+replace github.com/docker/docker => ./vendor/github.com/docker/docker
+
+replace github.com/ory/dockertest => ./vendor/github.com/ory/dockertest
