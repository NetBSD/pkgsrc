$NetBSD: patch-bin_tests_system_kasp_tests.sh,v 1.1 2020/08/09 15:20:22 taca Exp $

Fix shell portability.

--- bin/tests/system/kasp/tests.sh.orig	2020-07-03 10:44:14.000000000 +0000
+++ bin/tests/system/kasp/tests.sh
@@ -320,7 +320,7 @@ check_key() {
 	# Check file existence.
 	[ -s "$KEY_FILE" ] || ret=1
 	[ -s "$PRIVATE_FILE" ] || ret=1
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		[ -s "$STATE_FILE" ] || ret=1
 	fi
 	[ "$ret" -eq 0 ] || log_error "${BASE_FILE} files missing"
@@ -331,7 +331,7 @@ check_key() {
 	KEY_CREATED=$(awk '{print $3}' < "${ZONE}.${KEY_ID}.${_alg_num}.created")
 
 	grep "Created: ${KEY_CREATED}" "$PRIVATE_FILE" > /dev/null || log_error "mismatch created in $PRIVATE_FILE"
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "Generated: ${KEY_CREATED}" "$STATE_FILE" > /dev/null || log_error "mismatch generated in $STATE_FILE"
 	fi
 
@@ -344,9 +344,9 @@ check_key() {
 	grep "Private-key-format: v1.3" "$PRIVATE_FILE" > /dev/null || log_error "mismatch private key format in $PRIVATE_FILE"
 	grep "Algorithm: ${_alg_num} (${_alg_string})" "$PRIVATE_FILE" > /dev/null || log_error "mismatch algorithm in $PRIVATE_FILE"
 	# Now check the key state file.
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "This is the state of key ${_key_id}, for ${_zone}." "$STATE_FILE" > /dev/null || log_error "mismatch top comment in $STATE_FILE"
-		if [ "$_lifetime" == "none" ]; then
+		if [ "$_lifetime" = "none" ]; then
 			grep "Lifetime: " "$STATE_FILE" > /dev/null && log_error "unexpected lifetime in $STATE_FILE"
 		else
 			grep "Lifetime: ${_lifetime}" "$STATE_FILE" > /dev/null || log_error "mismatch lifetime in $STATE_FILE"
@@ -438,13 +438,13 @@ check_timingmetadata() {
 	if [ "$_published" = "none" ]; then
 		grep "; Publish:" "${_key_file}" > /dev/null && log_error "unexpected publish comment in ${_key_file}"
 		grep "Publish:" "${_private_file}" > /dev/null && log_error "unexpected publish in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Published: " "${_state_file}" > /dev/null && log_error "unexpected publish in ${_state_file}"
 		fi
 	else
 		grep "; Publish: $_published" "${_key_file}" > /dev/null || log_error "mismatch publish comment in ${_key_file} (expected ${_published})"
 		grep "Publish: $_published" "${_private_file}" > /dev/null || log_error "mismatch publish in ${_private_file} (expected ${_published})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Published: $_published" "${_state_file}" > /dev/null || log_error "mismatch publish in ${_state_file} (expected ${_published})"
 		fi
 	fi
@@ -452,13 +452,13 @@ check_timingmetadata() {
 	if [ "$_syncpublish" = "none" ]; then
 		grep "; SyncPublish:" "${_key_file}" > /dev/null && log_error "unexpected syncpublish comment in ${_key_file}"
 		grep "SyncPublish:" "${_private_file}" > /dev/null && log_error "unexpected syncpublish in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "PublishCDS: " "${_state_file}" > /dev/null && log_error "unexpected syncpublish in ${_state_file}"
 		fi
 	else
 		grep "; SyncPublish: $_syncpublish" "${_key_file}" > /dev/null || log_error "mismatch syncpublish comment in ${_key_file} (expected ${_syncpublish})"
 		grep "SyncPublish: $_syncpublish" "${_private_file}" > /dev/null || log_error "mismatch syncpublish in ${_private_file} (expected ${_syncpublish})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "PublishCDS: $_syncpublish" "${_state_file}" > /dev/null || log_error "mismatch syncpublish in ${_state_file} (expected ${_syncpublish})"
 		fi
 	fi
@@ -466,13 +466,13 @@ check_timingmetadata() {
 	if [ "$_active" = "none" ]; then
 		grep "; Activate:" "${_key_file}" > /dev/null && log_error "unexpected active comment in ${_key_file}"
 		grep "Activate:" "${_private_file}" > /dev/null && log_error "unexpected active in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Active: " "${_state_file}" > /dev/null && log_error "unexpected active in ${_state_file}"
 		fi
 	else
 		grep "; Activate: $_active" "${_key_file}" > /dev/null || log_error "mismatch active comment in ${_key_file} (expected ${_active})"
 		grep "Activate: $_active" "${_private_file}" > /dev/null || log_error "mismatch active in ${_private_file} (expected ${_active})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Active: $_active" "${_state_file}" > /dev/null || log_error "mismatch active in ${_state_file} (expected ${_active})"
 		fi
 	fi
@@ -480,13 +480,13 @@ check_timingmetadata() {
 	if [ "$_retired" = "none" ]; then
 		grep "; Inactive:" "${_key_file}" > /dev/null && log_error "unexpected retired comment in ${_key_file}"
 		grep "Inactive:" "${_private_file}" > /dev/null && log_error "unexpected retired in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Retired: " "${_state_file}" > /dev/null && log_error "unexpected retired in ${_state_file}"
 		fi
 	else
 		grep "; Inactive: $_retired" "${_key_file}" > /dev/null || log_error "mismatch retired comment in ${_key_file} (expected ${_retired})"
 		grep "Inactive: $_retired" "${_private_file}" > /dev/null || log_error "mismatch retired in ${_private_file} (expected ${_retired})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Retired: $_retired" "${_state_file}" > /dev/null || log_error "mismatch retired in ${_state_file} (expected ${_retired})"
 		fi
 	fi
@@ -494,13 +494,13 @@ check_timingmetadata() {
 	if [ "$_revoked" = "none" ]; then
 		grep "; Revoke:" "${_key_file}" > /dev/null && log_error "unexpected revoked comment in ${_key_file}"
 		grep "Revoke:" "${_private_file}" > /dev/null && log_error "unexpected revoked in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Revoked: " "${_state_file}" > /dev/null && log_error "unexpected revoked in ${_state_file}"
 		fi
 	else
 		grep "; Revoke: $_revoked" "${_key_file}" > /dev/null || log_error "mismatch revoked comment in ${_key_file} (expected ${_revoked})"
 		grep "Revoke: $_revoked" "${_private_file}" > /dev/null || log_error "mismatch revoked in ${_private_file} (expected ${_revoked})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Revoked: $_revoked" "${_state_file}" > /dev/null || log_error "mismatch revoked in ${_state_file} (expected ${_revoked})"
 		fi
 	fi
@@ -508,13 +508,13 @@ check_timingmetadata() {
 	if [ "$_removed" = "none" ]; then
 		grep "; Delete:" "${_key_file}" > /dev/null && log_error "unexpected removed comment in ${_key_file}"
 		grep "Delete:" "${_private_file}" > /dev/null && log_error "unexpected removed in ${_private_file}"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Removed: " "${_state_file}" > /dev/null && log_error "unexpected removed in ${_state_file}"
 		fi
 	else
 		grep "; Delete: $_removed" "${_key_file}" > /dev/null || log_error "mismatch removed comment in ${_key_file} (expected ${_removed})"
 		grep "Delete: $_removed" "${_private_file}" > /dev/null || log_error "mismatch removed in ${_private_file} (expected ${_removed})"
-		if [ "$_legacy" == "no" ]; then
+		if [ "$_legacy" = "no" ]; then
 			grep "Removed: $_removed" "${_state_file}" > /dev/null || log_error "mismatch removed in ${_state_file} (expected ${_removed})"
 		fi
 	fi
@@ -586,7 +586,7 @@ key_unused() {
 	grep "Revoke:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected revoked in $PRIVATE_FILE"
 	grep "Delete:" "$PRIVATE_FILE" > /dev/null && log_error "unexpected removed in $PRIVATE_FILE"
 
-	if [ "$_legacy" == "no" ]; then
+	if [ "$_legacy" = "no" ]; then
 		grep "Published: " "$STATE_FILE" > /dev/null && log_error "unexpected publish in $STATE_FILE"
 		grep "Active: " "$STATE_FILE" > /dev/null && log_error "unexpected active in $STATE_FILE"
 		grep "Retired: " "$STATE_FILE" > /dev/null && log_error "unexpected retired in $STATE_FILE"
@@ -1324,7 +1324,7 @@ set_keytimes_algorithm_policy() {
 	set_keytime    "KEY1" "PUBLISHED" "${created}"
 	set_keytime    "KEY1" "ACTIVE"    "${created}"
 	# Key was pregenerated.
-	if [ "$1" == "pregenerated" ]; then
+	if [ "$1" = "pregenerated" ]; then
 		keyfile=$(key_get KEY1 BASEFILE)
 		grep "; Publish:" "${keyfile}.key" > published.test${n}.key1
 		published=$(awk '{print $3}' < published.test${n}.key1)
@@ -1351,7 +1351,7 @@ set_keytimes_algorithm_policy() {
 	set_keytime    "KEY2" "PUBLISHED" "${created}"
 	set_keytime    "KEY2" "ACTIVE"    "${created}"
 	# Key was pregenerated.
-	if [ "$1" == "pregenerated" ]; then
+	if [ "$1" = "pregenerated" ]; then
 		keyfile=$(key_get KEY2 BASEFILE)
 		grep "; Publish:" "${keyfile}.key" > published.test${n}.key2
 		published=$(awk '{print $3}' < published.test${n}.key2)
@@ -1374,7 +1374,7 @@ set_keytimes_algorithm_policy() {
 	set_keytime    "KEY3" "PUBLISHED" "${created}"
 	set_keytime    "KEY3" "ACTIVE"    "${created}"
 	# Key was pregenerated.
-	if [ "$1" == "pregenerated" ]; then
+	if [ "$1" = "pregenerated" ]; then
 		keyfile=$(key_get KEY3 BASEFILE)
 		grep "; Publish:" "${keyfile}.key" > published.test${n}.key3
 		published=$(awk '{print $3}' < published.test${n}.key3)
@@ -2541,12 +2541,12 @@ rollover_predecessor_keytimes() {
 	set_addkeytime  "KEY1" "PUBLISHED"   "${_created}" "${_addtime}"
 	set_addkeytime  "KEY1" "SYNCPUBLISH" "${_created}" "${_addtime}"
 	set_addkeytime  "KEY1" "ACTIVE"      "${_created}" "${_addtime}"
-	[ "$Lksk" == 0 ] || set_retired_removed "KEY1" "${Lksk}" "${IretKSK}"
+	[ "$Lksk" = 0 ] || set_retired_removed "KEY1" "${Lksk}" "${IretKSK}"
 
 	_created=$(key_get KEY2 CREATED)
 	set_addkeytime  "KEY2" "PUBLISHED"   "${_created}" "${_addtime}"
 	set_addkeytime  "KEY2" "ACTIVE"      "${_created}" "${_addtime}"
-	[ "$Lzsk" == 0 ] || set_retired_removed "KEY2" "${Lzsk}" "${IretZSK}"
+	[ "$Lzsk" = 0 ] || set_retired_removed "KEY2" "${Lzsk}" "${IretZSK}"
 }
 
 # Key properties.
@@ -2994,7 +2994,7 @@ csk_rollover_predecessor_keytimes() {
 	set_addkeytime      "KEY1" "PUBLISHED"   "${_created}" "${_addksktime}"
 	set_addkeytime      "KEY1" "SYNCPUBLISH" "${_created}" "${_addzsktime}"
 	set_addkeytime      "KEY1" "ACTIVE"      "${_created}" "${_addzsktime}"
-	[ "$Lcsk" == 0 ] || set_retired_removed "KEY1" "${Lcsk}" "${IretCSK}"
+	[ "$Lcsk" = 0 ] || set_retired_removed "KEY1" "${Lcsk}" "${IretCSK}"
 }
 
 #
@@ -3908,8 +3908,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy uses the same keys ($n)"
 ret=0
-[ $_migrate_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migrate_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migrate_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migrate_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 # Test migration to dnssec-policy, existing keys do not match key algorithm.
@@ -4024,8 +4024,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy keeps existing keys ($n)"
 ret=0
-[ $_migratenomatch_algnum_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migratenomatch_algnum_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migratenomatch_algnum_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migratenomatch_algnum_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 # Test migration to dnssec-policy, existing keys do not match key length.
@@ -4141,8 +4141,8 @@ dnssec_verify
 n=$((n+1))
 echo_i "check that of zone ${ZONE} migration to dnssec-policy keeps existing keys ($n)"
 ret=0
-[ $_migratenomatch_alglen_ksk == $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
-[ $_migratenomatch_alglen_zsk == $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
+[ $_migratenomatch_alglen_ksk = $(key_get KEY1 ID) ] || log_error "mismatch ksk tag"
+[ $_migratenomatch_alglen_zsk = $(key_get KEY2 ID) ] || log_error "mismatch zsk tag"
 status=$((status+ret))
 
 #
