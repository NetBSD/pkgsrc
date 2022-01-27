# dq

### Authoritative example - streamlined DNSCurve query (executed 23.11.2013):

    $ dq -a a dnscurve.org uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    1 dnscurve.org - streamlined DNSCurve:
    320 bytes, 1+2+3+3 records, response, authoritative, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.142
    answer: dnscurve.org 600 A 131.193.32.147
    authority: dnscurve.org 259200 NS uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org
    additional: uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org 259200 A 131.193.32.142
    additional: uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org 259200 A 131.155.71.143
    additional: uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org 259200 A 80.101.159.118

### Authoritative example - TXT DNSCurve query, using suffix 'dnscurve.org'
(executed 23.11.2013):

    $ dq -S 'dnscurve.org' -a a dnscurve.org uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    1 dnscurve.org - txt DNSCurve:
    320 bytes, 1+2+3+3 records, response, authoritative, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.142
    answer: dnscurve.org 600 A 131.193.32.147
    authority: dnscurve.org 259200 NS uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org
    additional: uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org 259200 A 131.193.32.142
    additional: uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org 259200 A 131.155.71.143
    additional: uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org 259200 A 80.101.159.118

### Authoritative example - streamlined DNSCurve query, using IPv4 and key
(executed 23.11.2013):

    $ dq -k uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090 -a a dnscurve.org 131.155.71.143
    1 dnscurve.org - streamlined DNSCurve:
    320 bytes, 1+2+3+3 records, response, authoritative, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.147
    answer: dnscurve.org 600 A 131.193.32.142
    authority: dnscurve.org 259200 NS uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org
    additional: uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org 259200 A 131.193.32.142
    additional: uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org 259200 A 131.155.71.143
    additional: uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org 259200 A 80.101.159.118

### Authoritative example - streamlined DNSCurve query, using IPv6 and key
(executed 23.11.2013):
    
    $ dq -a -k uz52zufj724bjt11s3pgk2dtcpw8ww1dr8g3ssm3hs3jkmwr8l090p a blinkenlights.ch 2a01:4f8:120:43c1::a
    1 blinkenlights.ch - streamlined DNSCurve:
    341 bytes, 1+1+3+3 records, response, authoritative, noerror
    query: 1 blinkenlights.ch
    answer: blinkenlights.ch 86400 A 78.46.72.150
    authority: blinkenlights.ch 259200 NS uz5crn6x92t4vb4k3z68du7rmwmnnvkbdd29t79yzg9fr2s2rx5pk0.nsde1.eqmx.net
    authority: blinkenlights.ch 259200 NS uz5mnv8n4dzrp95zl50jryb4wgf45my27q6pvx8f540l9sspkcwvtm.nszh1.eqmx.net
    authority: blinkenlights.ch 259200 NS uz52zufj724bjt11s3pgk2dtcpw8ww1dr8g3ssm3hs3jkmwr8l090p.dns1.workaround.ch
    additional: uz5crn6x92t4vb4k3z68du7rmwmnnvkbdd29t79yzg9fr2s2rx5pk0.nsde1.eqmx.net 86400 A 178.209.50.169
    additional: uz5mnv8n4dzrp95zl50jryb4wgf45my27q6pvx8f540l9sspkcwvtm.nszh1.eqmx.net 86400 A 46.246.93.162
    additional: uz52zufj724bjt11s3pgk2dtcpw8ww1dr8g3ssm3hs3jkmwr8l090p.dns1.workaround.ch 86400 A 78.46.72.150

### Recursive example (executed 23.11.2013):

    $ dq a dnscurve.org
    1 dnscurve.org - regular DNS:
    272 bytes, 1+2+3+0 records, response, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.147
    answer: dnscurve.org 600 A 131.193.32.142
    authority: dnscurve.org 259200 NS uz5hjgptn63q5qlch6xlrw63tf6vhvvu6mjwn0s31buw1lhmlk14kd.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5dz39x8xk8wyq3dzn7vpt670qmvzx0zd9zg4ldwldkv6kx9ft090.ns.dnscurve.org
    authority: dnscurve.org 259200 NS uz5uu2c7j228ujjccp3ustnfmr4pgcg5ylvt16kmd0qzw7bbjgd5xq.ns.dnscurve.org

### Recursive example, using OpenDNS resolver - IPv6 (executed 23.11.2013):
    
    $ dq a dnscurve.org 2620:0:ccc::2
    1 dnscurve.org - regular DNS:
    62 bytes, 1+2+0+0 records, response, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.147
    answer: dnscurve.org 600 A 131.193.32.142

### Recursive example, using OpenDNS resolver - IPv4 (executed 23.11.2013):

    $ dq a dnscurve.org 208.67.222.222
    1 dnscurve.org - regular DNS:
    62 bytes, 1+2+0+0 records, response, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.142
    answer: dnscurve.org 600 A 131.193.32.147

### Recursive example, using OpenDNS resolver - IPv4, dnsqr backward
compatibility (executed 23.11.2013):

    env DNSCACHEIP=208.67.222.222 dq a dnscurve.org
    1 dnscurve.org - regular DNS:
    62 bytes, 1+2+0+0 records, response, noerror
    query: 1 dnscurve.org
    answer: dnscurve.org 600 A 131.193.32.142
    answer: dnscurve.org 600 A 131.193.32.147

### Recursive example, PTR query (executed 23.11.2013):

    $ dq ptr 1.0.0.127.in-addr.arpa
    12 1.0.0.127.in-addr.arpa - regular DNS:
    63 bytes, 1+1+0+0 records, response, noerror
    query: 12 1.0.0.127.in-addr.arpa
    answer: 1.0.0.127.in-addr.arpa 655360 PTR localhost

### Recursive example, PTR query, auto-rewrite to *.in-addr.arpa (executed
23.11.2013):

    $ dq ptr 127.0.0.1
    12 1.0.0.127.in-addr.arpa - regular DNS:
    63 bytes, 1+1+0+0 records, response, noerror
    query: 12 1.0.0.127.in-addr.arpa
    answer: 1.0.0.127.in-addr.arpa 655360 PTR localhost

### Recursive example, PTR query, auto-rewrite to *.ip6.arpa (executed
23.11.2013):

    $ dq ptr 2a01:4f8:120:43c1::aa
    12 a.a.0.0.0.0.0.0.0.0.0.0.0.0.0.0.1.c.3.4.0.2.1.0.8.f.4.0.1.0.a.2.ip6.arpa - regular DNS:
    90 bytes, 1+0+0+0 records, response, authoritative, nxdomain
    query: 12 a.a.0.0.0.0.0.0.0.0.0.0.0.0.0.0.1.c.3.4.0.2.1.0.8.f.4.0.1.0.a.2.ip6.arpa

### Authoritative example, verbose mode, truncated answer (executed
23.11.2013):

    $ dq -a -vv any google.com ns4.google.com
    dq: debug: resolving: ns4.google.com
    dq: debug: DNS query: ns4.google.com AAAA UDP 127.10.10.10 53: sent
    dq: debug: DNS query: ns4.google.com A UDP 127.10.10.10 53: sent
    dq: debug: DNS query: ns4.google.com A UDP 127.10.10.10 53: received
    dq: debug: DNS query: ns4.google.com AAAA UDP 127.10.10.10 53: received
    dq: debug: resolved: ns4.google.com: ns4.google.com 216.239.38.10
    dq: debug: DNS query: google.com ANY UDP 216.239.38.10 53: sent
    dq: debug: DNS query: google.com ANY UDP 216.239.38.10 53: failed: truncated
    dq: debug: DNS query: google.com ANY TCP 216.239.38.10 53: sent
    dq: debug: DNS query: google.com ANY TCP 216.239.38.10 53: received
    255 google.com - regular DNS:
    577 bytes, 1+24+0+0 records, response, authoritative, noerror
    query: 255 google.com
    answer: google.com 300 A 173.194.112.97
    answer: google.com 300 A 173.194.112.96
    answer: google.com 300 A 173.194.112.104
    answer: google.com 300 A 173.194.112.98
    answer: google.com 300 A 173.194.112.99
    answer: google.com 300 A 173.194.112.103
    answer: google.com 300 A 173.194.112.110
    answer: google.com 300 A 173.194.112.100
    answer: google.com 300 A 173.194.112.102
    answer: google.com 300 A 173.194.112.105
    answer: google.com 300 A 173.194.112.101
    answer: google.com 300 AAAA 2a00:1450:4001:803::1006
    answer: google.com 86400 SOA ns1.google.com dns-admin.google.com 2013100300 7200 1800 1209600 300
    answer: google.com 600 MX 10 aspmx.l.google.com
    answer: google.com 86400 257 \000\005issuesymantec.com
    answer: google.com 345600 NS ns3.google.com
    answer: google.com 345600 NS ns2.google.com
    answer: google.com 345600 NS ns1.google.com
    answer: google.com 600 MX 20 alt1.aspmx.l.google.com
    answer: google.com 600 MX 30 alt2.aspmx.l.google.com
    answer: google.com 345600 NS ns4.google.com
    answer: google.com 600 MX 50 alt4.aspmx.l.google.com
    answer: google.com 600 MX 40 alt3.aspmx.l.google.com
    answer: google.com 3600 TXT v=spf1 include:_spf.google.com ip4:216.73.93.70/31 ip4:216.73.93.72/31 ~all
